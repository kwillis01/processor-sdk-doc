.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_DSS

Overview
--------

Introduction
^^^^^^^^^^^^

The Display Subsystem (DSS) is a flexible, multi-pipeline subsystem that
supports high-resolution display outputs. DSS includes input pipelines
providing multi-layer blending with transparency to enable on-the-fly
composition. Various pixel processing capabilities are supported,
such as color space conversion and scaling, among others. DSS
includes a DMA engine, which allows direct access to the frame buffer
(device system memory). Display outputs can connect seamlessly to an
Open LVDS Display Interface transmitter (OLDITX), or can directly drive
device pads as a parallel video output interface.
This document has detailed API description that user can use
to make use of the DSS driver.


User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

.. rubric::  **DSS Configuration Structure**
   :name: dss-configuration-structure

For details about individual fields of DSS library structure, see the
Doxygen help by opening
PDK_INSTALL_DIR\\packages\\ti\\drv\\dss\\docs\\doxygen\\html\\index.html.

APIs
^^^^^

The DSS driver API can be broadly divided into the following categories

-  DSS Display API - API for video display drivers
-  DSS Display Controller API - API for controlling and configuring
   Video Ports in the display subsystem

In addition to above drivers the DSS package also includes many sample
examples which show how to use the drivers in different ways. Many of
these sample examples use a common set of APIs which a user may find
useful to refer to for use in their final application.

API reference for application:

::

    #include <ti/drv/dss/include/dss_<func>.h>

Application
------------

Examples
^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | | Description         | | Expected Results    |
+=======================+=======================+=======================+
| Display Dss           | | Example             | | Application shows   |
| application           |   demonstrating       |   two different       |
|                       |   *simple* display    |   buffer on OLDI panel|
|                       |   bgra frames         |   and success messages|
|                       |   to the OLDI use     |   on CCS console.     |
|                       |   case. Reference     |                       |
|                       |   example for         |                       |
|                       |   developers          |                       |
+-----------------------+-----------------------+-----------------------+
| Display Dss           | | Example             | | Application shows   |
| application (Bare     |   demonstrating       |   two different       |
| metal)                |   *simple* display    |   buffer on OLDI panel|
|                       |   bgra frames         |   and success messages|
|                       |   to the OLDI use     |   on CCS console.     |
|                       |   case. Reference     |                       |
|                       |   example for         |                       |
|                       |   developers          |                       |
+-----------------------+-----------------------+-----------------------+
| Display Dss Colorbar  | | Example             | | Application shows   |
| application           |   demonstrating       |   internal colorbar   |
|                       |   internal colorbar   |   on OLDI panel       |
|                       |   to the OLDI panel.  |   and success messages|
|                       |   Reference example   |   on CCS console.     |
|                       |   for developers.     |                       |
+-----------------------+-----------------------+-----------------------+

Additional References
---------------------

+-----------------------------------+----------------------------------------+
| **Document**                      | **Location**                           |
+-----------------------------------+----------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti    |
|                                   | \\drv\\dss\\docs\\doxygen\\html\\index.|
|                                   | html                                   |
+-----------------------------------+----------------------------------------+

Building DSS examples
---------------------

-  DSS examples and dependent libraries are built from the top level dss
   makefile
-  cd <pdk>/packages/ti/drv/dss
-  To build: make -s PDK_INSTALL_PATH=<pdk>/packages
-  To clean: make -s clean PDK_INSTALL_PATH=<pdk>/packages

DSS examples
------------

.. rubric::  *Description*
   :name: description

DSS examples exploits the DISPC (Display Controller) and OLDI output
available in the SoC. The example works on outputing pre-loaded
video frames of BGRA8888 formats to OLDI interface. The example also
demonstrates displaying videos combined from VID1 and VIDL1 pipelines
to OLDI panel. The example is also enhanced to show the display controller
scaling features.

|

.. rubric::  **Running the Display examples**
   :name: running-the-display-examples

**Configuring Display**:

-  Make sure the OLDI panel is connected to the base EVM before running
   the example binary.

**CCS connection**:

-  Load the System firmware as specified in SCICLIENT documentation
-  Load the generated executable file in CCS
-  Run the application.
-  Content will be displayed on the OLDI panel connected to EVM
