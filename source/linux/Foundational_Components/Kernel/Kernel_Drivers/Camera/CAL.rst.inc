.. http://processors.wiki.ti.com/index.php/Linux_Core_CAL_User%27s_Guide

Introduction
^^^^^^^^^^^^^


This page gives a basic description of Camera Abstraction Layer (CAL)
hardware and the Linux kernel driver (**ti-cal**). The technical
reference manual (TRM) for the SoC in question, and the board
documentation give more detailed descriptions.

Release Applicable
""""""""""""""""""""

This page applies to TI's v4.4, v4.1 and v3.14 kernel. Also CAL was
merged upstream in v4.6 kernel.

Supported Devices
""""""""""""""""""""

The CAL IP is only available on the following TI SoCs or SoC families:

-  AM571x
-  DRA72x

| 

Hardware Architecture
^^^^^^^^^^^^^^^^^^^^^^^^^^

On supported SoCs the Camera Abstraction Layer (CAL) module is used for
video capture from CSI-2 and camera sensor.

.. Image:: ../images/CAL-block-diagram.png
   :scale: 65 %

CAL provides up to two MIPI CSI-2 interfaces:

-  Module throughput up to 304 MPix/s
-  Transfer of pixels and data received by up to two D-PHY receivers
   (CSI2 PHY1 and CSI2 PHY2) to:

   -  System memory, through 128-bit master interface on L3\_MAIN
      interconnect
   -  VIP module, through a video port

-  Shared FIFO with 8 KiB size
-  Maximum data rate of 1.2 Gbps per D-PHY i.e. Byte clock up to 150 Mhz
   (per errata i904)
-  Data merger for 2-, 3-, or 4-data lane configuration
-  Maximum frame size 65535 bytes x 16383 lines
-  Error detection and correction
-  Eight contexts to support eight dedicated configurations of virtual
   channel ID and data types
-  On-the-fly differential pulse code modulation (DPCM) decompression

SoC Hardware Feature
""""""""""""""""""""

-  AM571x/DRA72x

   -  CAL provides two MIPI CSI-2 interfaces

      -  CSI2\_PHY1 with 4 data lanes / 1 clock lane
      -  CSI2\_PHY2 with 2 data lanes / 1 clock lane

Driver Architecture
^^^^^^^^^^^^^^^^^^^^^^^^^^

The CAL driver is a video capture driver built around the V4L2 framework
and is located in the directory drivers/media/platform/ti-vpe/ in the
kernel tree.

Linux kernel driver for the CAL is implemented as per the V4L2 standard
for capture devices. CAL driver is responsible only for the programming
of the CAL device and built-ins D-PHY. For programming external video
devices, we need a V4L2 subdevice driver which is used in conjunction
with the V4L2 driver. It also uses some of the helper kernel libraries
videobuf2 (VB2) for common buffer operations, queue management and
memory management.

-  `Linux Media Subsystem
   Documentation <https://linuxtv.org/downloads/v4l-dvb-apis/>`__
-  `Video for Linux
   API <https://linuxtv.org/downloads/v4l-dvb-apis-new/uapi/v4l/v4l2.html>`__
-  `V4L2 videobuf2 functions and data
   structures <https://linuxtv.org/downloads/v4l-dvb-apis/kapi/v4l2-videobuf2.html>`__
-  `V4L2
   sub-devices <https://linuxtv.org/downloads/v4l-dvb-apis-new/kapi/v4l2-subdev.html>`__

V4L2 endpoint device tree bindings
""""""""""""""""""""""""""""""""""""""""

Different camera / video sources have different configuration parameters
when interfacing with the CAL video ports. Common interfacing properties
like data-lanes and clock-lanes can be different across different
devices. V4L2 endpoint allows to describe these as part of device tree
definition. This makes the CAL driver generic enough to have no
dependency on the camera device. It also provides the flexibility to
work with new cameras by doing simple device tree modifications.

-  `V4L2 endpoint
   documentation <https://www.kernel.org/doc/Documentation/devicetree/bindings/media/video-interfaces.txt>`__

Following is an example showcasing the DT entries of CAL device node and
its usage when interfacing with a video source.

+-----------------------------------------------------+-------------------------------------------------+
| CAL device definition                               | Camera device definition                        |
+=====================================================+=================================================+
| ::                                                  | ::                                              |
|                                                     |                                                 |
|     cal {                                           |     ov490@24 {                                  |
|         #address-cells = <1>;                       |         compatible = "ovti,ov490";              |
|         #size-cells = <0>;                          |         reg = <0x24>                            |
|         status = "okay";                            |         ...                                     |
|         ports {                                     |         port {                                  |
|             #address-cells = <1>;                   |             csi2_cam0: endpoint@0 {             |
|             #size-cells = <0>;                      |                 clock-lanes = <0>;              |
|                                                     |                 data-lanes = <1 2 3 4>;         |
|             csi2_0: port@0 {                        |                 remote-endpoint = <&csi2_phy0>; |
|                  reg = <0>;                         |             };                                  |
|                  status = "okay";                   |         };                                      |
|                  csi2_phy0: endpoint@0 {            |      };                                         |
|                      slave-mode;                    |                                                 |
|                      remote-endpoint = <&csi2_cam0>;|                                                 |
|                  };                                 |                                                 |
|             };                                      |                                                 |
|             ...                                     |                                                 |
|             csi2_1: port@1 {                        |                                                 |
|                  reg = <1>;                         |                                                 |
|                  ...                                |                                                 |
|             };                                      |                                                 |
|         };                                          |                                                 |
|     };                                              |                                                 |
+-----------------------------------------------------+-------------------------------------------------+


V4L2 asynchronous subdevice registration
""""""""""""""""""""""""""""""""""""""""

Each camera device that CAL driver communicates to is modelled as a V4L2
subdevice. In the probe sequence, CAL and camera drivers are probed at
different time. V4L2 async subdevice binding helps to bind the CAL
device and the camera device together. CAL driver looks for the camera
entries in the endpoints and registers (v4l2\_async\_notifier\_register)
a callback if any of the requested devices become available.
cal\_async\_bound implements the priority based binding which allows to
have multiple cameras muxed against same video port. The device tree
order determines which of these gets picked up by the driver. Note that
the V4L2 g/s\_input ioctls are not supported, userspace won't be able to
select specific camera with these ioctls.

Of course the target subdevice driver also needs to support the
asynchronous registration framework. On top of this the subdevice driver
**must** implements the following ioctls for the handshake with the CAL
driver to work properly:

-  get\_fmt()
-  set\_fmt()
-  enum\_mbus\_code()
-  enum\_frame\_sizes()
-  s\_stream()

| 

Driver Features
^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: this is not a comprehensive list of features supported/not
supported.

Supported Features
""""""""""""""""""""

-  Maximum frame size limited by software to 1920x1200 pixels
-  Pixel formats (output)

   -  Runtime pixel format availability is based on the sub-device capability
   -  Use "yavta --enum-formats /dev/video1" to get an accurate list
   -  Since CAL does not perform any format conversion the supported format are limited to native pixel format supported by the sub-device driver

      -  YUV422 (YUYV,UYVY,VYUY,YVYU)
      -  RGB (15, 16, 24, 32 bits)
      -  Raw Bayer (8, 10, 12 bits)
-  V4L2 single-planar buffers and interface
-  Supports MMAP buffers (allocated by kernel from global CMA pool) and
   also allows to export them as DMABUF
-  Supports DMABUF import (Reusing buffers from other drivers)

Unsupported Features/Limitations
""""""""""""""""""""""""""""""""""""""""

-  Media Controller Framework
-  Cropping/Selection ioctls
-  Capture forwarding through VIP port
-  Multi-stream interleaving/multiplex per port (i.e multiple VCs per
   port)

| 

| 

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^

Kernel Configuration Options
""""""""""""""""""""""""""""""""""""""""

ti-cal supports building both as built-in or as a module.

ti-cal can be found under "Device Drivers/Multimedia support/V4L
platform devices" in the kernel menuconfig. You need to enable V4L2
(CONFIG\_MEDIA\_SUPPORT, CONFIG\_MEDIA\_CAMERA\_SUPPORT) and then enable
V4L platform driver (CONFIG\_V4L\_PLATFORM\_DRIVERS) before you can
enable ti-cal (CONFIG\_VIDEO\_TI\_CAL).

| 

Driver Usage
^^^^^^^^^^^^^

Loading ti-cal
""""""""""""""""""""

If built as a module, you need to load all the v4l2-common,
videobuf2-core and videobuf2-dma-contig modules before ti-cal will
start.

Using ti-cal
""""""""""""""""""""

When ti-cal is enabled, the capture device will appear as /dev/videoX.
Standard V4L2 user space applications can be used as long as the
capability of the application matches.

-  **dmabuftest example**

   Use CAL to capture a 1280x800 YUYV video stream and display it on an
   HDMI display using DMABUF buffers.

::

    dmabuftest -s 36:1920x1080 -c 1280x800@YUYV -d /dev/video1

-  **yavta example**

   Capture 1280x800 YUYV video stream to file.

::

    yavta -c60 -fYUYV -Fvout_1280x800_yuyv.yuv -s1280x800 /dev/video1

dmabuftest can be found from:

::

    https://git.ti.com/glsdk/omapdrmtest

yavta can be found from:

::

    http://git.ideasonboard.org/yavta.git

v4l2-ctl can be found from:

::

    https://git.linuxtv.org/v4l-utils.git

Debugging
""""""""""""""""""""

As ti-cal driver is based on the V4L2 framework, framework level tracing
can be enable as follows:

-  echo 3 >/sys/class/video4linux/video1/dev\_debug

   This allows V4L2 ioctl calls to be logged.
|
-  echo 3 > /sys/module/videobuf2\_core/parameters/debug

   This allows VB2 buffers operation to be logged.
|
In addition ti-cal also has specific debug log which can be enabled as
follows:

-  echo 3 > /sys/module/ti\_cal/parameters/debug

Troubleshooting common capture problem
""""""""""""""""""""""""""""""""""""""""

**Bootup/Probe checks**

First thing to look for is if the video devices are created or not;
Check the bootlog for prints in the kernel bootlog.

::

    Check device probe status
    dmesg | grep ov490
    dmesg | grep video

Depending on the camera connected, the following prints can confirm the
probe being successful.

+-------------------------------------------------------+------------------------+
| Bootlog print                                         | Result                 |
+=======================================================+========================+
| ov490 4-0024: ov490 Product ID 4 Manufacturer ID 99   | Camera probe success   |
+-------------------------------------------------------+------------------------+
| ov490 4-0024: Failed reading register 0x300a!         | Camera not connected   |
| ov490: probe of 4-0024 failed with error -121         |                        |
+-------------------------------------------------------+------------------------+

Alternatively you could also try to list all video devices:

::

    v4l2-ctl --list-devices

This would shows all video device and which driver they belong to.

**No video captured**

When the capture application is launched, it is expected to start video
capture and display frames on to display. Sometimes, no video is
displayed on the screen. To identify this being an issue with capture,
simple test can be done. Each CAL module has a dedicated interrupt line.
If the capture is successful, the interrupt count should increase
periodically.

::

    Check interrupts to confirm capture failure
    cat /proc/interrupts | grep cal
    360:        120          CBAR 119 Level   cal

In the above example, one can conclude that

-  Capture from one or more CAL ports is working fine.

Note that the IRQs are shared for different ports of the same instance.
This means, *cal* line will carry interrupts from both csi2\_0 and
csi2\_1 ports.

If the number of interrupt stays at zero or no longer changes this
usually means that the CAL engine does not detect video data. This might
be cause by a handshake failure between the CSI2 D-PHY and the actual
sensor or the sensor is not generating any data at all. Verifying that
the clock pins or data pins are properly toggling might be necessary.

**Camera isn't started, clock, data lanes are dead**

This is a root cause where the camera board is not generating video
signals in the desired format. Subdevice s\_stream op is supposed to
perform all the I2C transactions to indicate sensor to start streaming.
Failing to get the proper clock at this time indicates some issue in the
camera configuration. Most cameras have a power pin driver by one of the
GPIO, make sure that the subdev driver requests for this GPIO.
|  One other cause maybe due to incorrect board mux or pinmux
configuration. It does not hurt to double check these.

**Video is being captured but image is distorted**

If the image is distorted, you should double check that the sensor is
generating the expected pixel clock. Also when trying to view the
captured video, make sure you use the same frame size as used to capture
it.

TI Board Specific Information
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

None at this time.