
Overview
----------
Detailed test procedure and additional HW setup needed for running the processor SDK board diagnostic tests are explained
in the following sections. Logs shown for each test are for sample reference, actual logs may slightly vary from platform to platform.

Two different modes of diagnostic tests are supported - Functional and Stress. Functional tests verify basic functionality of an
interface to confirm the interface HW connectivity. Stress tests verify the functionality of an interface under stress conditions which will
confirm the stability of the HW interface.

Refer to `Diagnostic Applications <index_board.html#diagnostic-applications>`_ section for details of the platforms
supported by each of the diagnostic tests described below.

Application/Daughter cards required for running the test are not mentioned in the test setup assuming the tests are run with full HW kit.

Functional Tests
------------------
This section describes the test procedure and setup for diagnostic functional tests.

Accelerometer Test
^^^^^^^^^^^^^^^^^^
This test verifies the Accelerometer sensor on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘accelerometer_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for Accelerometer test is shown below

::

    *********************************************
    *         Accelerometer Test                *
    *********************************************

    Test:                Expected Result:    Actual Result:    Result:
    ----------------     ----------------    --------------    -------
    0x32                 PASS
    Self-Test(X Axis)    120-550             247               PASS
    Self-Test(Y axis)    120-550             192               PASS
    Self-Test(Z Axis)    140-750             349               PASS
    Exiting

|

ADC Test
^^^^^^^^^^^^^
This test verifies ADC interface on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘adc_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for ADC test is shown below

::

    *********************************************
    *                 ADC Test                  *
    *********************************************

    Voltage sensed on the AN0 line : 846mV
    Voltage sensed on the AN1 line : 1156mv

    Test PASSED!

|

Boot EEPROM Test
^^^^^^^^^^^^^^^^^
This test verifies Boot EEPROM memory. First and last page of the EEPROM are written with
a test pattern and read back for data verification.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
Make sure pins 2-3 of J44 and J45 headers on AM65x CP board are shorted

Test Execution
"""""""""""""""
 - Select the menu option to run ‘bootEeprom_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for boot EEPROM test is shown below

::

    *********************************************
    *              Boot EEPROM Test             *
    *********************************************

    Running Boot EEPROM test

    Detecting the Boot EEPROM device...

    Boot EEPROM device detection successful

    Boot EEPROM boundary verification test...

    Verifying the Boot EEPROM first page...

    Verifying the Boot EEPROM last page...

    Boot EEPROM boundary verification test successful

    Boot EEPROM test Passed

|

Boot Switch Test
^^^^^^^^^^^^^^^^^^
Test verifies boot mode switch by configuring boot strap pins as GPIOs and reading the
pin state with boot switch set in different patterns. Test prompts to set the boot switch
with a specific pattern and waits for user confirmation of the setting.
ON-OFF-ON... sequence indicated by the test starts from switch position 1.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘bootSwitch_TEST’
 - Setup the boot switch as instructed by the serial console log
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for boot switch test is shown below

::

    *********************************************
    *             Boot Switch Test              *
    *********************************************
    Set All switches to OFF
    Press Enter after setting the switches

    Set the Switches to ON-OFF-ON-OFF...
    Press Enter after setting the switches

    Set the Switches to OFF-ON-OFF-ON...
    Press Enter after setting the switches

    Set All switches to ON
    Press Enter after setting the switches

    Test Passed
|


Button Test
^^^^^^^^^^^^^^^^^
Verifies push buttons on the board. Test prompts for pressing a specific button
which should be detected by the test and displayed on the console.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘button_TEST’
 - Press the button as instructed by the test messages on the serial console.
 - Verify the test log on serial console. Make sure the button press is detected properly.

.. note::
   Button release detection is supported only on AM65xx platform.

Test Log
"""""""""""
Sample log for push button test is shown below

::

    *********************************************
    *                 Button Test               *
    *********************************************

    Running button test...
    Button SW  5            WAIT      Waiting for button press Button Pressed
    Button SW  5            WAIT      Waiting for button release Button released
    Button SW  5            PASS
    Button SW  6            WAIT      Waiting for button press Button Pressed
    Button SW  6            WAIT      Waiting for button release Button released
    Button SW  6            PASS
    Test PASSED!

|

Buzzer Test
^^^^^^^^^^^^
This test verifies the Buzzer interface on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘buzzer_TEST’
 - Verify the Buzzer sound on the HW platform
 - Verify the test log on serial console
 - Press 'y' to confirm proper buzzer output or any other key to indicate failure

Test Log
"""""""""
Sample log for buzzer test is shown below

::

    *********************************************
    *               Buzzer Test                *
    *********************************************

    Testing Buzzer sound
    Press 'y' to verify pass: y
    Received: y

    Test PASSED!
|

Clock Generator Test
^^^^^^^^^^^^^^^^^^^^^^
This test verifies clock generator interface on the HW platform under test.
Need to probe and confirm the clocks during the test.

Test Accessories
"""""""""""""""""
Oscilloscope to verify the clock outputs

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘clock_TEST’
 - Verify the test log on serial console
 - Verify the clock generator output clocks and confirm the result on the serial console

Test Log
"""""""""""
Sample log for clock generator test is shown below

::

    **********************************
           CLOCK GENERATOR Test
    **********************************

    Running Clock generator Detect Test

    Clock generator Detection Successful!

    Clock generator Detect Test Passed!


    Running Clock generator probe Test

    Probe the clock generator clock outputs
    Are the signals generated properly ?
    Press 'Y' to confirm, any other key to deny
    y

    Clock generator probe Test Passed!

    Clock generator Test Passed!

    Clock generator Tests Completed!!

    -----------------X-----------------

|

Current Monitor Test
^^^^^^^^^^^^^^^^^^^^^^
Test reads the voltage and current values from different current monitor devices available on the board.
All the current monitor devices available on the board are verified during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
For iceK2G, this test expects J16 and J17 to be connected with jumper
shunts. This enables the current monitors to be used.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘currentMonitor_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for current monitor test is shown below

::

    **********************************************
    *            Current Monitor Test            *
    **********************************************

    Running Current Monitor Test...

    Verifying Device VDD_CORE at Address - 0x40
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 16777
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 9
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 800
    Bus Voltage = 1000mV
    Reading the Power register...
    Power Register Value = 3
    Power = 915mW
    Reading the Current register...
    Current Register Value = 74
    Current = 11mA


    Verifying Device VDD_MCU at Address - 0x41
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 16777
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 1534
    Shunt Voltage = 3mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 797
    Bus Voltage = 996mV
    Reading the Power register...
    Power Register Value = 501
    Power = 19108mW
    Reading the Current register...
    Current Register Value = 12566
    Current = 383mA


    Verifying Device VDD_MPU at Address - 0x42
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 27962
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 6
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 802
    Bus Voltage = 1002mV
    Reading the Power register...
    Power Register Value = 3
    Power = 503mW
    Reading the Current register...
    Current Register Value = 82
    Current = 7mA


    Verifying Device SoC_DVDD3V3 at Address - 0x43
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 27962
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 15
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 2665
    Bus Voltage = 3331mV
    Reading the Power register...
    Power Register Value = 28
    Power = 2670mW
    Reading the Current register...
    Current Register Value = 205
    Current = 18mA


    Verifying Device SoC_DVDD1V8 at Address - 0x44
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 5592
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 108
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 1442
    Bus Voltage = 1802mV
    Reading the Power register...
    Power Register Value = 21
    Power = 3204mW
    Reading the Current register...
    Current Register Value = 295
    Current = 26mA


    Verifying Device SoC_AVDD1V8 at Address - 0x45
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 41943
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 1196
    Shunt Voltage = 2mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 1442
    Bus Voltage = 1802mV
    Reading the Power register...
    Power Register Value = 387
    Power = 14760mW
    Reading the Current register...
    Current Register Value = 5358
    Current = 65mA


    Verifying Device SoC_VDDS_DDR at Address - 0x46
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 8388
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 256
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 956
    Bus Voltage = 1195mV
    Reading the Power register...
    Power Register Value = 50
    Power = 1335mW
    Reading the Current register...
    Current Register Value = 1049
    Current = 63mA


    Verifying Device VDD_DDR at Address - 0x47
    Setting the configuration register...
    Setting the calibration register...
    Calibration Value = 8388
    Reading the Shunt Voltage register...
    Shunt Voltage Register Value = 38
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage Register Value = 957
    Bus Voltage = 1196mV
    Reading the Power register...
    Power Register Value = 8
    Power = 689mW
    Reading the Current register...
    Current Register Value = 156
    Current = 9mA

|

DCAN Test
^^^^^^^^^^
This test verifies the DCAN ports on the HW platform under test.
Test supports verifying the DCAN interface in internal and external loopback modes.

Test Accessories
"""""""""""""""""
DCAN loopback cable (for evmK2G)

Test Setup
"""""""""""
Connect two DCAN ports (P2 and P3) with DCAN loopback cable - only on evmK2G

Test Execution
""""""""""""""""
 - Select the menu option to run ‘dcan_TEST’
 - Follow the instructions on serial console to select the DCAN instance
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for DCAN test is shown below

::

    *********************************************
    *                 DCAN Test                 *
    *********************************************


    **** DCAN APPLICATION TEST ****
    Menu:
    1. DCAN External Loopback test - DCAN1 Instance
    2. DCAN Internal Loopback test - DCAN2 Instance
    x. Exit
    Select DCAN APPLICATION TEST : 1

    DCAN External Loopback Test App: DCAN1 MSG OBJ 1 (TX) to DCAN1 MSG OBJ 2 (RX)

    DCAN -- External Loopback Testmode test Passed!!


    **** DCAN APPLICATION TEST ****
    Menu:
    1. DCAN External Loopback test - DCAN1 Instance
    2. DCAN Internal Loopback test - DCAN2 Instance
    x. Exit
    Select DCAN APPLICATION TEST : 2

    DCAN Internal Loopback Test App: DCAN2 MSG OBJ 1 (TX) to DCAN2 MSG OBJ 2 (RX)

    DCAN -- Internal Loopback Testmode test Passed!!


    **** DCAN APPLICATION TEST ****
    Menu:
    1. DCAN External Loopback test - DCAN1 Instance
    2. DCAN Internal Loopback test - DCAN2 Instance
    x. Exit
    Select DCAN APPLICATION TEST : x

    DCAN Application Test exiting...

|

EEPROM Test
^^^^^^^^^^^^^^^^^^^^^
This test reads and displays the board ID details from the EEPROM memory.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘eeprom_TEST’
 - Verify the board ID details displayed on the serial console

Test Log
"""""""""""
Sample log for Board ID EEPROM test is shown below

::

    *********************************************
    *              EEPROM Test                  *
    *********************************************
    header: aa5533ee
    boardName: 66AK2GICE
    version: 1.0A
    serialNum: 09164P540001
    Test PASSED!

|

.. note::
   Board ID content shown in the above log changes from platform to platform.


EMAC Test
^^^^^^^^^^^
This test verifies the EMAC Ethernet port on HW platform under test.
Ethernet link and data transmit/receive are verified during this test.
Ethernet interface is configured for 100mbps speed and 10 packets are sent/received during the test.
Ethernet cable disconnect/reconnect and data transfer after cable connection is also verified during the test.

Test Accessories
""""""""""""""""""
Ethernet loopback cables/plugs

Test Setup
"""""""""""
Connect the Ethernet loopback cables to the EMAC Ethernet port (RJ-45) on the board.
Check below table for the details of EMAC Ethernet ports used by the test on different platforms.

+---------------+-----------------+
| HW Platform   | Ethernet Port   |
+===============+=================+
| iceK2G        | J10             |
+---------------+-----------------+
| am65xx_evm    | J12 on CP board |
+---------------+-----------------+
| am65xx_idk    | J12 on CP board |
+---------------+-----------------+

Test Execution
""""""""""""""""
 - Select the menu option to run ‘emac_TEST’
 - Follow the instructions on serial console for disconnecting and connecting the cable during the test.
 - Verify the test log on serial console


Test Log
"""""""""

Sample log for Ethernet loopback test is shown below

::

    ************************************************
    *             ETHERNET LOOPBACK Test           *
    ************************************************

    Reading Ethernet PHY Register Dump...
    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x7949
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x8c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077
    EMAC loopback test application initialization
    main: emac_open success
    Configuring Phy
    Waiting for Link Status
    Link is UP!!

    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5
    Sending Packet: 6
    Sending Packet: 7
    Sending Packet: 8
    Sending Packet: 9
    Sending Packet: 10
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5
    Received Packet: 6
    Received Packet: 7
    Received Packet: 8
    Received Packet: 9
    Received Packet: 10

    Packets sent: 10, Packets received: 10

    Ethernet Loopback test passed
    All tests completed
    Please disconnect the loopback cable
    Link is Down
    Please reconnect the loopback cable
    Link is UP

    Reading Ethernet PHY Register Dump...
    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1000
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4006
    PHY Register 0x0009 - 0x1000
    PHY Register 0x000a - 0x0000
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077
    EMAC loopback test application initialization
    main: emac_open success
    Configuring Phy
    Waiting for Link Status
    Link is UP!!

    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5
    Sending Packet: 6
    Sending Packet: 7
    Sending Packet: 8
    Sending Packet: 9
    Sending Packet: 10
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5
    Received Packet: 6
    Received Packet: 7
    Received Packet: 8
    Received Packet: 9
    Received Packet: 10

    Packets sent: 10, Packets received: 10

    Ethernet Loopback test passed
    All tests completed

|

eMMC Test
^^^^^^^^^^
This test verifies eMMC memory interface on the HW platform under test.
16KB of data is written and read during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘emmc_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for eMMC test is shown below

::

    *********************************************
    *                 eMMC Test                 *
    *********************************************

    PASS: Read/Write Success for this pattern
|

External RTC Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies setting the time, date and running the clock for on-board RTC interface.
RTC configuration is done through I2C interface. Time and date are read for 5 times for every 5secs
during the test to demonstrate operation of the RTC clock.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘extRtc_TEST’
 - Verify the test log on serial console
 - Confirm the test result by pressing 'y' if RTC time/date changes properly or press any key for failure

Test Log
"""""""""""
Sample log for external RTC test is shown below

::

    *********************************************
    *                 RTC Test                  *
    *********************************************

    Setting Time...

    Setting Date...

    Reading Time...

    Reading Date...


    Displaying time: 11:59:53 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 11:59:57 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 12:0:2 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:7 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:12 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:17 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19
    If the time and date increment, press 'y' to indicate pass or any other character to indicate failure
    y

    RTC test passed...

|

GMAC Test
^^^^^^^^^^
This test verifies the GMAC Ethernet ports of the HW platform under test.

Test Accessories
"""""""""""""""""
Ethernet loopback cables/plugs

Test Setup
"""""""""""
Connect the Ethernet loopback cables to the GMAC Ethernet port (RJ-45) on the board.
Check below table for the details of GMAC Ethernet ports used by the test on different platforms.

+---------------+-----------------+
| HW Platform   | Ethernet Port   |
+===============+=================+
| idkAM571x     | J10 & J12       |
+---------------+-----------------+
| idkAM572x     | J10 & J12       |
+---------------+-----------------+
| idkAM574x     | J10 & J12       |
+---------------+-----------------+
| evmAM572x     | Both ports of P5|
+---------------+-----------------+

Test Execution
""""""""""""""""
 - Select the menu option to run ‘gmac_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for GMAC test is shown below

::

    *********************************************
    *                 GMAC Test                 *
    *********************************************
    Test                    Port    Link    Link-Speed              Status    Error
    --------------------    ----    ----    --------------------    ------    ---------------------------
    Phy Loopback               1    Up    Phy Loopback            PASS
    10Mbps Full-Duplex         1    Up    10Mbps Full duplex      PASS
    100Mbps Half-Duplex        1    Up    100Mbps Half duplex     PASS
    100Mbps Full-Duplex        1    Up    100Mbps Full duplex     PASS
    Phy Loopback               2    Up    Phy Loopback            PASS
    10Mbps Full-Duplex         2    Up    10Mbps Full duplex      PASS
    100Mbps Half-Duplex        2    Up    100Mbps Half duplex     PASS
    100Mbps Full-Duplex        2    Up    100Mbps Full duplex     PASS
    Exiting
|

Haptics Test
^^^^^^^^^^^^
This verifies haptics motor using vibrations on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘haptics_TEST’
 - Verify the test log on serial console
 - Check for the vibrations on the HW platform

Test Log
"""""""""
Sample log for Haptics test is shown below

::

    *********************************************
    *               Haptics Test                *
    *********************************************

    Testing Haptics (vibration)
    Press 'y' to verify pass: y
    Received: y

    Test PASSED!
|

HDMI Test
^^^^^^^^^^
This test verifies HDMI display port on the HW platform under test.
Color bar and different colors are displayed on HDMI monitor during the test.

Test Accessories
"""""""""""""""""
 - HDMI Display
 - HDMI cable

Test Setup
"""""""""""
Connect the HDMI Display to the HDMI port on the board.
Check below table for the details of HDMI ports used by the test on different platforms.

+---------------+-----------------+
| HW Platform   | HDMI Port       |
+===============+=================+
| evmK2G        | J36             |
+---------------+-----------------+

Test Execution
""""""""""""""""
 - Select the menu option to run ‘hdmi_TEST’
 - Verify the color bar and different colors displayed on the HDMI Monitor.
 - Verify the test log on serial console and confirm test result.

Test Log
"""""""""
Sample log for HDMI test is shown below

::

    ***********************
           HDMI Test
    ***********************
    Running HDMI Device Detect Test
    sil9022 HDMI Chip version = b0
    HDMI Device Detect Test Passed

    Displaying Colorbar... WAIT  Press 'y' if Colorbar is displayed, any other key for failure: y
    Display Colorbar   - PASS
    Displaying WHITE... WAIT  Press 'y' if WHITE is displayed, any other key for failure: y
    Display WHITE - PASS
    Displaying BLUE... WAIT  Press 'y' if BLUE is displayed, any other key for failure: y
    Display BLUE - PASS
    Displaying GREEN... WAIT  Press 'y' if GREEN is displayed, any other key for failure: y
    Display GREEN - PASS
    Displaying RED... WAIT  Press 'y' if RED is displayed, any other key for failure: y
    Display RED - PASS
    Displaying PURPLE... WAIT  Press 'y' if PURPLE is displayed, any other key for failure: y
    Display PURPLE - PASS
    Displaying PINK... WAIT  Press 'y' if PINK is displayed, any other key for failure: y
    Display PINK - PASS
    Displaying BLACK... WAIT  Press 'y' if BLACK is displayed, any other key for failure: y
    Display BLACK - PASS
    Displaying YELLOW... WAIT  Press 'y' if YELLOW is displayed, any other key for failure: y
    Display YELLOW - PASS

    HDMI Tests Completed!!

    -----------------X-----------------

|

ICSS EMAC Test
^^^^^^^^^^^^^^
This test verifies ICSS EMAC Ethernet port on HW platform under test.
PRU-ICSS Ethernet ports are configured for 100mbps speed and 5 packets are sent/received during the test.

Test Accessories
"""""""""""""""""
Ethernet loopback cables/plugs

Test Setup
"""""""""""
Connect the Ethernet loopback cables to the PRU-ICSS Ethernet ports (RJ-45) on the board.
Check below table for the details of Ethernet ports used by the test on different platforms.

+---------------+-----------------------+
| HW Platform   | ICSS Ethernet Port    |
+===============+=======================+
| idkAM571x     | J6                    |
+---------------+-----------------------+
| idkAM572x     | J6                    |
+---------------+-----------------------+
| idkAM574x     | J6                    |
+---------------+-----------------------+
| iceK2G        | All ports of J8 & J9  |
+---------------+-----------------------+

Test Execution
""""""""""""""""
 - Select the menu option to run ‘icssEmac_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for ICSS EMAC test is shown below

::

    PRU_ICSS0 Loopback Test
    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS0 port 0 LINK IS UP
    PRU_ICSS0 port 1 LINK IS UP

    Sending Packets on Port 0
    Sending Pkt 0
    Received pkt: 0
    Sending Pkt 1
    Received pkt: 1
    Sending Pkt 2
    Received pkt: 2
    Sending Pkt 3
    Received pkt: 3
    Sending Pkt 4
    Received pkt: 4

    Sending Packets on Port 1
    Sending Pkt 0
    Received pkt: 0
    Sending Pkt 1
    Received pkt: 1
    Sending Pkt 2
    Received pkt: 2
    Sending Pkt 3
    Received pkt: 3
    Sending Pkt 4
    Received pkt: 4
    All tests have passed

    PRU_ICSS0 Loopback Test Completed!


    PRU_ICSS1 Loopback Test
    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS1 port 0 LINK IS UP
    PRU_ICSS1 port 1 LINK IS UP

    Sending Packets on Port 0
    Sending Pkt 0
    Received pkt: 0
    Sending Pkt 1
    Received pkt: 1
    Sending Pkt 2
    Received pkt: 2
    Sending Pkt 3
    Received pkt: 3
    Sending Pkt 4
    Received pkt: 4

    Sending Packets on Port 1
    Sending Pkt 0
    Received pkt: 0
    Sending Pkt 1
    Received pkt: 1
    Sending Pkt 2
    Received pkt: 2
    Sending Pkt 3
    Received pkt: 3
    Sending Pkt 4
    Received pkt: 4
    All tests have passed

    PRU1_ICSS0 Loopback Test Completed!

|

ICSSG EMAC Test
^^^^^^^^^^^^^^^^^
This port to port Ethernet test verifies the PRU-ICSS gigabit Ethernet interface on the board under test.
During the test, Ethernet interface is configured for 1000mbps speed with one port of an ICSS instance
is connected to another port. 5 packets are sent from one port and received by another port.
Both the ports are verified for transmit and receive. All the ICSSG EMAC ports available on the board
verified during the test.
Note that ICSSG EMAC Test can also run on a am65xx_idk with Interposer daughter card. For details
of Interposer daughter card, please refer to  `Device Drivers <index_device_drv.html#emac>`_

Test Accessories
""""""""""""""""""
Ethernet cables

Test Setup
""""""""""""
Connect Ethernet cable between two ports of an PRU-ICSS instance. Make such connections on all the PRU-ICSS ports available
Check below table for the detials of ICSSG Ethernet ports used by the test on different platforms

+---------------+-----------------------+
| HW Platform   | ICSSG Ethernet Port   |
+===============+=======================+
| am65xx_evm    | Two ports on          |
|               | J14 of CP board.      |
+---------------+-----------------------+
| am65xx_idk    | Two ports on          |
|               | J14 of CP board.      |
|               |                       |
|               | Two ports on          |
|               | J1 of IDK board.      |
|               |                       |
|               | Two ports on          |
|               | J3 of IDK board.      |
+---------------+-----------------------+
| am65xx_idk    | Two ports on          |
| with          | J14 of CP board.      |
| Interposer    |                       |
| card          |                       |
|               | Two ports on          |
|               | J3 of IDK board.      |
+---------------+-----------------------+

Test Execution
""""""""""""""""
 - Select the menu option to run ‘icssgEmac_TEST’
 - Verify the test log on serial console


Test Log
""""""""""

Sample log for ICSGG Ethernet test is shown below

::

    ***************************************
    *           ICSSG EMAC TEST           *
    ***************************************


    Reading Ethernet PHY Register Dump...


    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x7c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0003
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0003
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0003
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x7c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0003
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x7c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0003
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0003
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077
    port 0:  FW is ready
    Port 0:  FlowId 2
    Port 0:  Config FW Complete
    port 1:  FW is ready
    Port 1:  FlowId 3
    Port 1:  Config FW Complete
    port 2:  FW is ready
    Port 2:  FlowId 10
    Port 2:  Config FW Complete
    port 3:  FW is ready
    Port 3:  FlowId 11
    Port 3:  Config FW Complete
    port 4:  FW is ready
    Port 4:  FlowId 18
    Port 4:  Config FW Complete
    port 5:  FW is ready
    Port 5:  FlowId 19
    Port 5:  Config FW Complete

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 0 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 1 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 2 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 3 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 4 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 5 LINK IS UP!


    Sending Packets on Port - 0
    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5

    Receiving Packets on Port - 1
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5

    Packets Sent: 5, Packets Received: 5
    Port 0 Send to Port 1 Receive Test Passed!


    Sending Packets on Port - 1
    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5

    Receiving Packets on Port - 0
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5

    Packets Sent: 5, Packets Received: 5
    Port 1 Send to Port 0 Receive Test Passed!


    Sending Packets on Port - 2
    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5

    Receiving Packets on Port - 3
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5

    Packets Sent: 5, Packets Received: 5
    Port 2 Send to Port 3 Receive Test Passed!


    Sending Packets on Port - 3
    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5

    Receiving Packets on Port - 2
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5

    Packets Sent: 5, Packets Received: 5
    Port 3 Send to Port 2 Receive Test Passed!


    Sending Packets on Port - 4
    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5

    Receiving Packets on Port - 5
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5

    Packets Sent: 5, Packets Received: 5
    Port 4 Send to Port 5 Receive Test Passed!


    Sending Packets on Port - 5
    Sending Packet: 1
    Sending Packet: 2
    Sending Packet: 3
    Sending Packet: 4
    Sending Packet: 5

    Receiving Packets on Port - 4
    Received Packet: 1
    Received Packet: 2
    Received Packet: 3
    Received Packet: 4
    Received Packet: 5

    Packets Sent: 5, Packets Received: 5
    Port 5 Send to Port 4 Receive Test Passed!


    ICSSG Ethernet Port to Port Test Passed!
    All Tests Completed

|

LCD Test
^^^^^^^^^^
This test verifies LCD display on the HW platform under test.
Displaying color bar, LCD backlight control and touch verification is done during the test.

Test Accessories
"""""""""""""""""
LCD Display

Test Setup
"""""""""""
Connect the LCD Display to the HW platform under test.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘lcd_TEST’
 - Verify the color bar displayed on the LCD display.
 - Verify that LCD backlight is getting changed during backlight control test
 - Provide touch inputs during the touch interface test and confirm that positions are detected properly
 - Verify the test log on serial console

.. note::
   Touch interface test is not supported on all the platforms.
   Refer to LCD Touchscreen Test for touch interface test on other platforms.

Test Log
"""""""""
Sample log for LCD test is shown below

::

    *********************************************
    *              Display Test                 *
    *********************************************

    LCD Board detect successfully

    Running LCD Display Test...
    DSS application started...
    LCD configured successfully
    Overlay configuration done
    Video Port configuration done
    Display the colour bar with maximum brightness

    LCD Display Test Successfully

    Running LCD Backlight Test

    Changing Backlight... WAIT, Check the LCD panel

    Increasing the brightness by varying the
    duty cycle percentage form 0 to 100...


    Decreasing the brightness by varying the
    duty cycle percentage form 100 to 0...
      Press 'y' if Brightness is Increasing & Decreasing, Any other key for failure: y
    Change Backlight - PASS

    Running LCD Touch Detect Test

    Running the LCD touch detect test...

    Reading the touch device details
    Reading the product ID...
    The prod Id read is - 928
    Reading the firmware version...
    The firmware version read is - `ABC
    Clearing the buffer status register...


    Waiting for user to provide 20 single point touches...
    (x - 371, y - 497)
    (x - 672, y - 284)
    (x - 371, y - 497)
    (x - 785, y - 620)
    (x - 819, y - 334)
    (x - 857, y - 449)
    (x - 387, y - 495)
    (x - 679, y - 314)
    (x - 792, y - 644)
    (x - 805, y - 428)
    (x - 821, y - 379)
    (x - 909, y - 570)
    (x - 909, y - 570)
    (x - 794, y - 697)
    (x - 807, y - 718)
    (x - 824, y - 747)
    (x - 952, y - 648)
    (x - 829, y - 753)
    (x - 839, y - 754)
    (x - 890, y - 442)
    LCD touch detect test passed!

|

LCD Touchscreen Test
^^^^^^^^^^^^^^^^^^^^^
This test verifies the LCD Touchscreen on the HW platform under test.

Test Accessories
"""""""""""""""""
LCD Display

Test Setup
"""""""""""
Connect the LCD Display to the HW platform under test.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘lcdTouchscreen_TEST’
 - Provide multiple touch points to verify multi-touch input detection
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for LCD Touchscreen test is shown below

::

    *********************************************
    *             Touchscreen Test              *
    *********************************************
    Input 9 touches to exit test
    Touch   t1              t2              t3              t4              t5              t6              t7              t8              t9
    1        343, 389       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    2        343, 389       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    3        343, 389       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    4        343, 389       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    5        343, 389       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    6        343, 389       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    7        426, 637       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    8        426, 637       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    9        426, 637       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095
    9        426, 637       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095       4095,4095

|

ICSS LED Test
^^^^^^^^^^^^^^
This test verifies LEDs connected to PRU-ICSS ports.
All the LEDs are turned ON and OFF for 3 times during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.


Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘icssgLed_TEST’
 - Confirm that all the PRU-ICSS LEDs on the board are toggling during the test
 - Verify the test log on serial console
 - Confirm the test result by pressing 'y' in case of success and any other key for failure

Test Log
"""""""""""
Sample log for ICSS LED test is shown below

::

    *********************************************
    *              ICSS LED Test                *
    *********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: y
    Received: y

    Test PASSED!

|

Industrial LED Test
^^^^^^^^^^^^^^^^^^^^
This test verifies industrial LEDs connected to I2C interface on the HW platform under test.
All the LEDs are turned ON and OFF for 3 times during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘ledIndustrial_TEST’
 - Confirm that all the industrial LEDs on the board are toggling during the test
 - Verify the test log on serial console
 - Confirm the test result by pressing 'y' in case of success and any other key for failure

Test Log
"""""""""""
Sample log for industrial LED test is shown below

::

    *********************************************
    *            Industrial LED Test            *
    *********************************************

    Running Industrial LED test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling Ethernet LEDs for 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: y
    Received: y

    Testing Industrial LEDs on AM65x IDK Board
    Cycling Ethernet LEDs for 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: y
    Received: y

    Industrial LED test Passed

|

LED Test
^^^^^^^^^^^
This test verifies general purpose user LEDs on the HW platform under test.
All the LEDs are turned ON and OFF for 3 times during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘led_TEST’
 - Confirm that all the general purpose user LEDs on the board are toggling during the test
 - Verify the test log on serial console
 - Confirm the test result by pressing 'y' in case of success or any other key for failure

Test Log
"""""""""""
Sample log for LED test is shown below

::

    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: y
    Received: y

    Test PASSED!

|

Light Sensor Test
^^^^^^^^^^^^^^^^^^
This test verifies the Ambient Light Sensor on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘ambient_light_sensor_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for Light Sensor test is shown below

::

    *********************************************
    *         Ambient Light Test                *
    *********************************************

    Test:                Expected Result:    Actual Result:    Result:
    ----------------     ----------------    --------------    -------
    PowerUp/Read         0x03                PASS
    Read ADC 0           >=0x80              0x95              PASS
    Read ADC 1           >=0x80              0xAC              PASS
    PowerDown            0x00                0x0               PASS
    Read ADC 0           0x00                0x00              PASS
    Read ADC 1           0x00                0x00              PASS

|

MCAN Test
^^^^^^^^^^
Verifies MCAN ports on the HW platform with two MCAN ports connected with each other.
Data is sent from one port and received on another port. Both the ports are verified for Tx and Rx.

Test Accessories
"""""""""""""""""
MCAN port to port loopback cable

Test Setup
"""""""""""
Connect two MCAN ports on the board to each other with MCAN cable.
Check below table for the details of MCAN ports used by the test on different platforms.

+---------------+-----------------+
| HW Platform   | MCAN Ports      |
+===============+=================+
| am65xx_idk    | Two ports on P1 |
|               | connector of    |
|               | IDK board       |
+---------------+-----------------+

Test Execution
"""""""""""""""
 - Select the menu option to run ‘mcan_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for MCAN test is shown below

::

    ***********************************************
    *                MCAN Test                    *
    ***********************************************
    MCANSS Revision ID:
    scheme:0x1
    Business Unit:0x2
    Module ID:0x8e0
    RTL Revision:0x5
    Major Revision:0x1
    Custom Revision:0x0
    Minor Revision:0x1
    CAN-FD operation is enabled through E-Fuse.
    Endianess Value:0x87654321
    Successfully configured MCAN0
    MCANSS Revision ID:
    scheme:0x1
    Business Unit:0x2
    Module ID:0x8e0
    RTL Revision:0x5
    Major Revision:0x1
    Custom Revision:0x0
    Minor Revision:0x1
    CAN-FD operation is enabled through E-Fuse.
    Endianess Value:0x87654321
    Successfully configured MCAN1


    Transmitting Data on MCAN Port0 and Receiving on MCAN port 1

    Sending Packet - 1

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0x30

    Message DataByte2:0xb9

    Message DataByte3:0xd6

    Message DataByte4:0xfb

    Message DataByte5:0x4b

    Message DataByte6:0x87

    Message DataByte7:0x27

    Message DataByte8:0x97

    Message DataByte9:0x58

    Message DataByte10:0x0

    Message DataByte11:0xc0

    Message DataByte12:0xd4

    Message DataByte13:0xe

    Message DataByte14:0x3

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x100008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0x30

    Message DataByte2:0xb9

    Message DataByte3:0xd6

    Message DataByte4:0xfb

    Message DataByte5:0x4b

    Message DataByte6:0x87

    Message DataByte7:0x27

    Message DataByte8:0x97

    Message DataByte9:0x58

    Message DataByte10:0x0

    Message DataByte11:0xc0

    Message DataByte12:0xd4

    Message DataByte13:0xe

    Message DataByte14:0x3

    Received Packet - 1


    Sending Packet - 2

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0xcb

    Message DataByte2:0x62

    Message DataByte3:0xc5

    Message DataByte4:0xf2

    Message DataByte5:0xf0

    Message DataByte6:0x42

    Message DataByte7:0xd0

    Message DataByte8:0x5e

    Message DataByte9:0x8

    Message DataByte10:0xf0

    Message DataByte11:0x26

    Message DataByte12:0x97

    Message DataByte13:0xb

    Message DataByte14:0x26

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xcb

    Message DataByte2:0x62

    Message DataByte3:0xc5

    Message DataByte4:0xf2

    Message DataByte5:0xf0

    Message DataByte6:0x42

    Message DataByte7:0xd0

    Message DataByte8:0x5e

    Message DataByte9:0x8

    Message DataByte10:0xf0

    Message DataByte11:0x26

    Message DataByte12:0x97

    Message DataByte13:0xb

    Message DataByte14:0x26

    Received Packet - 2


    Sending Packet - 3

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0xe4

    Message DataByte2:0xe6

    Message DataByte3:0x81

    Message DataByte4:0x1b

    Message DataByte5:0x8a

    Message DataByte6:0x71

    Message DataByte7:0x39

    Message DataByte8:0x78

    Message DataByte9:0x7a

    Message DataByte10:0xa7

    Message DataByte11:0x22

    Message DataByte12:0xdb

    Message DataByte13:0x19

    Message DataByte14:0x62

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xe4

    Message DataByte2:0xe6

    Message DataByte3:0x81

    Message DataByte4:0x1b

    Message DataByte5:0x8a

    Message DataByte6:0x71

    Message DataByte7:0x39

    Message DataByte8:0x78

    Message DataByte9:0x7a

    Message DataByte10:0xa7

    Message DataByte11:0x22

    Message DataByte12:0xdb

    Message DataByte13:0x19

    Message DataByte14:0x62

    Received Packet - 3


    Sending Packet - 4

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0x18

    Message DataByte2:0x13

    Message DataByte3:0x56

    Message DataByte4:0x19

    Message DataByte5:0x54

    Message DataByte6:0x55

    Message DataByte7:0xc6

    Message DataByte8:0x40

    Message DataByte9:0x45

    Message DataByte10:0xa0

    Message DataByte11:0x5a

    Message DataByte12:0x4e

    Message DataByte13:0x51

    Message DataByte14:0xdb

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0x18

    Message DataByte2:0x13

    Message DataByte3:0x56

    Message DataByte4:0x19

    Message DataByte5:0x54

    Message DataByte6:0x55

    Message DataByte7:0xc6

    Message DataByte8:0x40

    Message DataByte9:0x45

    Message DataByte10:0xa0

    Message DataByte11:0x5a

    Message DataByte12:0x4e

    Message DataByte13:0x51

    Message DataByte14:0xdb

    Received Packet - 4


    Sending Packet - 5

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0xf0

    Message DataByte2:0x79

    Message DataByte3:0x8a

    Message DataByte4:0xaa

    Message DataByte5:0x8b

    Message DataByte6:0xe3

    Message DataByte7:0x8f

    Message DataByte8:0x5c

    Message DataByte9:0xf6

    Message DataByte10:0x1c

    Message DataByte11:0xa0

    Message DataByte12:0x41

    Message DataByte13:0x4c

    Message DataByte14:0xeb

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xf0

    Message DataByte2:0x79

    Message DataByte3:0x8a

    Message DataByte4:0xaa

    Message DataByte5:0x8b

    Message DataByte6:0xe3

    Message DataByte7:0x8f

    Message DataByte8:0x5c

    Message DataByte9:0xf6

    Message DataByte10:0x1c

    Message DataByte11:0xa0

    Message DataByte12:0x41

    Message DataByte13:0x4c

    Message DataByte14:0xeb

    Received Packet - 5



    Transmitting Data on MCAN Port1 and Receiving on MCAN port 0

    Sending Packet - 1

    Message successfully transferred with payload Bytes:0xf
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0x1f

    Message DataByte2:0x44

    Message DataByte3:0x40

    Message DataByte4:0x68

    Message DataByte5:0x7a

    Message DataByte6:0x5d

    Message DataByte7:0xf5

    Message DataByte8:0x3e

    Message DataByte9:0xa5

    Message DataByte10:0xb7

    Message DataByte11:0xe3

    Message DataByte12:0x36

    Message DataByte13:0x3a

    Message DataByte14:0x76

    Received Packet - 1


    Sending Packet - 2

    Message successfully transferred with payload Bytes:0xf
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xb0

    Message DataByte2:0xbd

    Message DataByte3:0x67

    Message DataByte4:0x34

    Message DataByte5:0x8c

    Message DataByte6:0x9

    Message DataByte7:0x6

    Message DataByte8:0xab

    Message DataByte9:0x4c

    Message DataByte10:0x2b

    Message DataByte11:0x13

    Message DataByte12:0x4a

    Message DataByte13:0xe1

    Message DataByte14:0x7d

    Received Packet - 2


    Sending Packet - 3

    Message successfully transferred with payload Bytes:0xf
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xde

    Message DataByte2:0x32

    Message DataByte3:0xf2

    Message DataByte4:0x26

    Message DataByte5:0xb9

    Message DataByte6:0x8e

    Message DataByte7:0x4e

    Message DataByte8:0x65

    Message DataByte9:0x8d

    Message DataByte10:0xd5

    Message DataByte11:0xda

    Message DataByte12:0xee

    Message DataByte13:0x73

    Message DataByte14:0x7e

    Received Packet - 3


    Sending Packet - 4

    Message successfully transferred with payload Bytes:0xf
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xe7

    Message DataByte2:0x13

    Message DataByte3:0xa0

    Message DataByte4:0x99

    Message DataByte5:0xe

    Message DataByte6:0x63

    Message DataByte7:0x95

    Message DataByte8:0x3f

    Message DataByte9:0x27

    Message DataByte10:0xcf

    Message DataByte11:0xb2

    Message DataByte12:0xb0

    Message DataByte13:0xc5

    Message DataByte14:0xef

    Received Packet - 4


    Sending Packet - 5

    Message successfully transferred with payload Bytes:0xf
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xb1

    Message DataByte2:0x1c

    Message DataByte3:0xe5

    Message DataByte4:0xef

    Message DataByte5:0xaa

    Message DataByte6:0x40

    Message DataByte7:0x77

    Message DataByte8:0xac

    Message DataByte9:0x70

    Message DataByte10:0x77

    Message DataByte11:0x3

    Message DataByte12:0xef

    Message DataByte13:0xc5

    Message DataByte14:0x70

    Received Packet - 5


     MCAN diagnostic test completed.

|

McASP Audio Test
^^^^^^^^^^^^^^^^^
Verifies McASP audio interface on the board.
Audio samples are received through codec input and sent back to codec audio output during the test.
Codec control channel is verified through I2C interface and audio channel is verified through McASP interface.

Test Accessories
"""""""""""""""""
 - Audio LINE IN cable.
 - Headphone.

Test Setup
"""""""""""
Connect audio LINE IN cable to audio input port and headphone to audio output port on the HW platform under test.
Check below table for the details of audio ports used by the test on different platforms.

+---------------+-----------------+-----------------+
| HW Platform   | Audio IN Port   | Audio OUT Port  |
+===============+=================+=================+
| evmK2G        | J32             | J33             |
+---------------+-----------------+-----------------+
| evmOMAPL137   | P3              | P5              |
+---------------+-----------------+-----------------+

Test Execution
"""""""""""""""
 - Start playing audio at the audio source driving the audio input connected to input port
 - Select the menu option to run ‘mcasp_TEST’
 - Verify that the audio being played at input is looped back to audio headset/speaker connected to output port
 - Verify that the audio plays without any noise on left and right channels.
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for McASP audio test is shown below

::

    *********************************************
    *         AUDIO Loopback Test               *
    *********************************************

    Playing Audio on left channel

    Playing Audio on right channel

    Playing Audio on both left and right

    Audio Loopback test completed

|

McASP AudioDC Test
^^^^^^^^^^^^^^^^^^
This test verifies the audio interface on the multi-channel audio daughter card for the OMAPL137 EVM.

Test Accessories
"""""""""""""""""
 - 4 Audio LINE IN cables
 - 4 Headphones

Test Setup
"""""""""""
 - Connect LINE IN cables to all the audio input ports (J5 to J8) on the audio daughter card.
 - Connect headsets to all the audio output ports (J9 to J12) on the audio daughter card.

Test Execution
""""""""""""""""
 - Start playing audio at the audio source driving the audio input connected to input ports
 - Load and execute the McASP AudioDC test using CCS
 - Listen to the Audio played back through the Headphones
 - Verify that the audio plays without any noise on left and right channels.
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for McASP AudioDC test is shown below

::

    *******************************************
    *         Audio DC Loopback Test          *
    *******************************************

    Starting Audio Loopback...
    Check the Headset/Speaker Audio Output

    Audio DC Loopback Test Completed!
    Audio DC Loopback Test Passed!!

|

McSPI Test
^^^^^^^^^^^^
This test verifies reading the industrial input data through McSPI interface.
Need to provide input to industrial input channels while running the test.

Except for iceAMIC110, this test expects pins to be
connected to the Industrial I/O header. The Industrial I/O header,
has two columns in parallel, one of which is the McSPI input and the
other being VDD. Thus, connecting any row with a jumper will yield a '1'
read on that McSPI input. By connecting the first, second, third, and
forth row with jumpers would yield 0x1, 0x2, 0x4, and 0x8 being read
respectively.

Test Accessories
"""""""""""""""""
Wires to short pins on industrial I/O header.

Test Setup
"""""""""""
Short the rows on industrial I/O header.
Check below table for the details of industrial IO header used by the test on different platforms.

+---------------+-----------------------+
| HW Platform   | Industrial I/O Header |
+===============+=======================+
| idkAM571x     | J37                   |
+---------------+-----------------------+
| idkAM572x     | J37                   |
+---------------+-----------------------+
| idkAM574x     | J37                   |
+---------------+-----------------------+
| idkAM437x     | J1                    |
+---------------+-----------------------+


Test Execution
"""""""""""""""
 - Select the menu option to run ‘mcspi_TEST’
 - Verify the test log on serial console
 - Confirm the test result by pressing 'y' in case the input provided to industrial I/O header is read properly,
   else press any other key to indicate failure.

Test Log
"""""""""""
Sample log for McSPI test is shown below

::

    *********************************************
    *                MCSPI Test                 *
    *********************************************

    Testing MCSPI...
    Data transferred: aa
    Data received: 20
    Press 'y' to verify pass, 'r' to read again,
    or any other character to indicate failure: y
    User input:  y

    Test PASSED!
|

Memory (DDR) Test
^^^^^^^^^^^^^^^^^^
This test verifies the DDR memory of the HW platform under test.
Address bus test is performed with a test pattern and its compliment during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘mem_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""

Sample DDR test log is shown below

::

    *********************************************
    *              DDR Memory Test              *
    *********************************************

    Testing writing and reading memory
    board_external_memory_test: Start address (0x80000000),            end address (0xffffffff)
    First test started
    Writing to test area...
            Write up to 0x80000000 done
            Write up to 0x90000000 done
            Write up to 0xa0000000 done
            Write up to 0xb0000000 done
            Write up to 0xc0000000 done
            Write up to 0xd0000000 done
            Write up to 0xe0000000 done
            Write up to 0xf0000000 done
    Write finished!
    Checking values...
            Read up to 0x80000000 okay
            Read up to 0x90000000 okay
            Read up to 0xa0000000 okay
            Read up to 0xb0000000 okay
            Read up to 0xc0000000 okay
            Read up to 0xd0000000 okay
            Read up to 0xe0000000 okay
            Read up to 0xf0000000 okay
    Second test started
    Writing complementary values to test area...
            Write up to 0x80000000 done
            Write up to 0x90000000 done
            Write up to 0xa0000000 done
            Write up to 0xb0000000 done
            Write up to 0xc0000000 done
            Write up to 0xd0000000 done
            Write up to 0xe0000000 done
            Write up to 0xf0000000 done
    Write finished!
    Checking values...
            Read up to 0x80000000 okay
            Read up to 0x90000000 okay
            Read up to 0xa0000000 okay
            Read up to 0xb0000000 okay
            Read up to 0xc0000000 okay
            Read up to 0xd0000000 okay
            Read up to 0xe0000000 okay
            Read up to 0xf0000000 okay
    Board memory test passed!

|

MMCSD Test
^^^^^^^^^^^^^
This test verifies SD card interface on the platform under test.
16KB of data is written and read during the test.

Test Accessories
"""""""""""""""""
SD card.

Test Setup
"""""""""""
Insert the SD card into MMCSD slot of the board.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘mmcsd_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for SD card test is shown below

::

    *********************************************
    *                MMCSD Test                 *
    *********************************************

    PASS: Read/Write Success for this pattern

|

Nand Test
^^^^^^^^^
This test verifies NAND flash memory on the HW platform under test.
Reading the NAND flash information and NAND page write/read with different test patterns
is done during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘nand_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for NAND test is shown below

::

    ***********************
           NAND Test
    ***********************

    Running NAND Flash Chip Detect Test
    Device Id - 0x0
    Manufacturer Id - 0x0
    Device Width - 16
    Block Count - 2048
    Page Count - 64
    Page Size - 2048
    Spare Area Size - 64
    Column Address - 1024

    NAND Flash Chip Detect Test Passed

    Running NAND Flash Block Erase Test
    NAND Flash Test: Erase Data Verification Passed

    NAND Flash Block Erase Test Passed

    Running NAND Flash Memory Access Test - Test Pattern 1
    NAND Flash Test: Data Verification Passed

    Running NAND Flash Memory Access Test - Test Pattern 2
    NAND Flash Test: Data Verification Passed

    NAND Flash Memory Access Test Passed

    NAND Flash Test Passed!

    NAND Flash Tests Completed!!

    -----------------X-----------------

|

NOR Flash Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies the NOR flash memory connected to SPI interface.
One page of flash is written and read back for data verification during the test.


Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘norflash_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for NOR flash test is shown below

::

    *********************************************
    *            SPI FLASH Test                 *
    *********************************************
    Reading Flash Device ID...
    Device ID 0 - 0x20
    Device ID 1 - 0xba
    Device ID 2 - 0x18
    Flash Device ID Match!

    Flash Device ID Read Passed!

    Verifying Sector - 0
    Data Read matches with Data written
    SPI Flash Test Passed!

    SPI NOR Flash Test Passed

|

OLED Display Test
^^^^^^^^^^^^^^^^^
This test verifies the OLED display on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘oled_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for OLED Display test is shown below

::

    ********************************
            OLED DISPLAY Test
    ********************************

    Running Oled display Detect Test

    Oled display Detection Successful!

    Oled display Detect Test Passed!
    OLED LCD Display test PASS

    Oled display Test Passed!

    Oled Tests Completed!!

    -----------------X-----------------

|

OSPI Flash Test
^^^^^^^^^^^^^^^^^^^
This test verifies the flash memory connected to OSPI interface.
One page of flash is written and read back for data verification during the test.


Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘ospi_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for OSPI flash test is shown below

::

    *********************************************
    *            OSPI FLASH Test                *
    *********************************************

    OSPI NOR device ID: 0x5b1a, manufacturer ID: 0x2c

     Verifying the OSPI Flash first page...
    OSPI NOR Flash first page verification Successful

     Verifying the OSPI Flash last page...
    OSPI NOR Flash last page verification Successful

    OSPI NOR Flash verification Successful
|

PCIe (2-lane) Test
^^^^^^^^^^^^^^^^^^^
This test verifies the two-lane PCIe ports on the AM65x IDK kit.
Two AM65x IDK kits are required to run this test.
Both the boards should be equipped with SD cards having the same diagnostic test binaries.

.. note::
   Current version of test is exercising only one lane of the 2-lane PCIe card.

Test Accessories
"""""""""""""""""
 - Two AM65x IDK kits
 - PCIe two-lane cable

Test Setup
"""""""""""
 - Connect PCIe ports on both the IDK kits with a two-lane PCIe cable.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘pcie_TEST’ on both the boards
 - Press ‘R’ on first board serial console to enable rootcomplex operation
 - Press ‘E’ on second board serial console to enable endpoint operation
 - Verify the test log on serial console.

Test Log
"""""""""""
Sample log for 2-lane PCIe test is shown below

Sample log for board running in RC mode

::

    **********************************************
    *                PCIe Test                   *
    **********************************************
    Enter: E for Endpoint or R for Root Complex
    R
    * RC mode *
    This is PCIE RC
    Link is up
    link status reg =0x30130000
    Link speed:Gen3
    RC writes a pattern to EP
    RC received data, loopback test passed

|

Sample log for board running in EP mode

::

    **********************************************
    *                PCIe Test                   *
    **********************************************
    Enter: E for Endpoint or R for Root Complex
    E
    * EP mode *
    This is PCIE EP
    Link is up
    link status reg =0x10130000
    Link speed:Gen3
    EP received data and will write back

|

PCIe (1-lane) Test
^^^^^^^^^^^^^^^^^^^
This test verifies the one-lane PCIe ports on the AM65x EVM kit.
Two AM65x EVM kits are required to run this test.
Both the boards should be equipped with SD cards having the same diagnostic test binaries.

Test Accessories
"""""""""""""""""
 - Two AM65x EVM kits
 - PCIe one-lane cable

Test Setup
"""""""""""
 - Connect PCIe ports on both the EVM kits with a one-lane PCIe cable.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘pcie_TEST’ on both the boards
 - Press ‘R’ on first board serial console to enable rootcomplex operation
 - Press ‘E’ on second board serial console to enable endpoint operation
 - Verify the test log on serial console.

Test Log
"""""""""""
Sample log for 1-lane PCIe test is shown below

Sample log for board running in RC mode

::

    **********************************************
    *                PCIe Test                   *
    **********************************************
    Enter: E for Endpoint or R for Root Complex
    R
    * RC mode *
    This is PCIE RC
    Link is up
    link status reg =0x30130000
    Link speed:Gen3
    RC writes a pattern to EP
    RC received data, loopback test passed

|

Sample log for board running in EP mode

::

    **********************************************
    *                PCIe Test                   *
    **********************************************
    Enter: E for Endpoint or R for Root Complex
    E
    * EP mode *
    This is PCIE EP
    Link is up
    link status reg =0x10130000
    Link speed:Gen3
    EP received data and will write back

|

PMIC Test
^^^^^^^^^
This test verifies PMIC interface on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘pmic_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for PMIC test is shown below

::

    *********************************************
    *                PMIC Test                  *
    *********************************************
    Testing PMIC module...
    PMIC ID = 0x51043990
    Initial PMIC voltage = 0xff
    Setting PMIC voltage to 0x44
    done!
    PMIC voltage after = 0x44
    Setting PMIC voltage to original value
    Final voltage value = 0xff
    Test PASSED!
|

PWM Test
^^^^^^^^^
This test verifies the PWM module to generate a pulse of 1KHz with different
duty cycles on the HW platform under test.

Test Accessories
"""""""""""""""""
Oscilloscope to confirm the PWM output

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘pwm_TEST’
 - Verify the test log on serial console
 - Verify the PWM output to cofirm the duty cycle generated by the test

Refer below table for the PWM output signals generated by the test on different platforms

+---------------+-----------------+
| HW Platform   | PWM Output Pin  |
+===============+=================+
| evmK2G        | J12 pin 33      |
+---------------+-----------------+
| evmAM572x     | P17 pin 5       |
+---------------+-----------------+
| idkAM437x     | J16 pin 14      |
+---------------+-----------------+
| evmAM335x     | J5 pin 13       |
+---------------+-----------------+

Test Log
"""""""""
Sample log for PWM test is shown below

::

    *********************************************
    *                 PWM Test                  *
    *********************************************

    Generating 1KHz PWM pulse with 25 Duty Cycle

    Generating 1KHz PWM pulse with 50 Duty Cycle

    Generating 1KHz PWM pulse with 75 Duty Cycle

    PWM Test Completed!
|

QSPI Test
^^^^^^^^^
This test verifies the QSPI flash on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘qspi_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for QSPI test is shown below

::

    *********************************************
    *                 QSPI Test                 *
    *********************************************

    Testing QSPI read/write...
    Test PASSED!
|

Rotary Switch Test
^^^^^^^^^^^^^^^^^^^^^
This test verifies reading the rotary switch inputs on HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘rotarySwitch_TEST’
 - Verify the test log on serial console
 - Confirm the test result by pressing 'y' in case rotary switch input is read properly, else any other key to indicate failure.

Test Log
"""""""""""
Sample log for rotary switch test is shown below

::

    ********************************
           ROTARY SWITCH Test
    ********************************

    Running Rotary switch Detect Test

    Rotary switch Detection Successful!

    Rotary switch Detect Test Passed!

    Running Rotary switch position Test

    The rotary switch is at position 7

    Rotary switch position Test Passed!

    Press 'r' to run the test again,
    or any other character to exit: y

    Rotary switch Test Passed!

    Rotary switch Tests Completed!!

    -----------------X-----------------

|

RS485 UART Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies RS485 interface on platform under test.
RS485 interface is connected to PRU-ICSS port of the SoC.
Test outputs a test string through RS485 UART interface and receives user input as confirmation.
RS485 to RS232 USB cable is used on AM65x IDK platform to run the test.

Test Accessories
"""""""""""""""""
RS485 to RS232 USB cable (AM65x IDK)

Test Setup
"""""""""""
am65x_idk:
 - Connect RS485 to RS232 USB cable between RS485 UART port of the board and host PC.
 - Setup serial console application on host PC with below configurations
 ::

    Baud rate    -    115200
    Data length  -    8 bit
    Parity       -    None
    Stop bits    -    1
    Flow control -    None

Test Execution
"""""""""""""""
am65x_idk:
 - Select the menu option to run ‘rs485_TEST’
 - Verify the test log on serial console
 - Confirm the test result on RS485 UART console

Test Log
"""""""""""
Sample log for RS485 UART test (am65xx_idk) is shown below

Main test console log
::

    *********************************************
    *           PRU-ICSS UART Test              *
    *********************************************

    Check PRU UART console for the test logs

    PRU-ICSS UART Test Passed!!

    PRU-ICSS UART Test Completed!
|

RS485 UART console log
::

    *********************************************
    *           PRU-ICSS UART Test              *
    *********************************************

    Testing UART print to console at 115.2k baud rate
    Press 'y' to verify pass: Test Passed
|

RTC Test
^^^^^^^^^
This test verifies the on-chip RTC Timer on the HW platform under test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘rtc_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for RTC test is shown below

::

    ***********************************************
    *                 RTC Test                    *
    ***********************************************

    Current Date and Time:
    10:23:52  21:6:16 Sunday
    Test Passed!
|

Temperature Sensor Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies reading the ambient temperature from temperature sensor interface.
Test verifies all the temperature sensor devices on the board.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘temperature_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for temperature sensor test is shown below

::

    *********************************************
    *          Temperature Sensor Test          *
    *********************************************

    Running temperature sensor test...
    Read temperature register value - 568

    Temperature read from the temperature sensor
     target address - 0x48 is 35 degree centigrade
    Read temperature register value - 520

    Temperature read from the temperature sensor
     target address - 0x49 is 32 degree centigrade
    Temperature sensor test Passed!

|

Timer Test
^^^^^^^^^^^
This test verifies the on-chip timer module to generate 1msec tick on the HW platform under test.
Test waits for 2secs counting the timer interrupt.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
""""""""""""""""
 - Select the menu option to run ‘timer_TEST’
 - Verify the test log on serial console
 - Verify the time that tests waits counting the timer interrupts
 - Press 'y' if the test waits for 2secs or press any key in case wait time is more or less than 2secs

Test Log
"""""""""
Sample log for Timer test is shown below

::

    *********************************************
    *              1MSEC TIMER Test             *
    *********************************************

    Timer Configured for 1msec interrupt
    Enabling Timer Interrupts
    Test waits till Timer generates 2000 (~2secs) interrupts

    Press 'y' if timer ran for correct duration, else any other key:y

    Test PASSED!
|

UART Test
^^^^^^^^^^^^
This test verifies the UART serial port by sending a test string to the UART serial console
and reading user input to confirm the test result.

Test Accessories
"""""""""""""""""
UART serial cable.
Different platforms may need different cable for verifying the serial port. Refer to HW manual
for more details.

Test Setup
"""""""""""
 - Connect the UART serial cable between the board and host PC
 - Setup serial console application on host PC with below configurations
 ::

    Baud rate    -    115200
    Data length  -    8 bit
    Parity       -    None
    Stop bits    -    1
    Flow control -    None

 - Four UART ports are verified on am65xx_evm platform and three UART ports are verified on am65xx_idk platform.
   Need to make above setup on all serial consoles connected to multiple ports on these platforms.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘uart_TEST’
 - Verify the test log on serial console. Verify the test log on all the serial consoles in case
   the HW platform supports more than one serial port

Test Log
"""""""""""
Sample UART test log is shown below

::

    *********************************************
    *                 UART Test                 *
    *********************************************

    Testing UART print to console at 115.2k baud rate
    Press 'y' to verify pass: y
    Received: y

    Test PASSED!

|

UART2USB Test
^^^^^^^^^^^^^^
This test verifies the UART to USB serial port interface on K2G EVM.

Test Accessories
"""""""""""""""""
mini USB cable

Test Setup
"""""""""""
 - Connect the UART serial cable between the board (J23) and host PC
 - Setup serial console application on host PC with below configurations
 ::

    Baud rate    -    115200
    Data length  -    8 bit
    Parity       -    None
    Stop bits    -    1
    Flow control -    None

Test Execution
""""""""""""""""
 - Select the menu option to run ‘uart2usb_TEST’
 - Verify the test log on serial console

Test Log
"""""""""
Sample log for UART2USB test is shown below

Log on the main test console
::

    *************************************************
    *                 UART2USB Test                 *
    *************************************************

    Check the messages on UART2USB console

    Received: y
    Test PASSED!
|

Log on the UART to USB test console
::

    Testing UART print to console at 115.2k baud rate
    Press 'y' to verify pass: y

|

USB Device Test
^^^^^^^^^^^^^^^^^^
This test verifies USB device mode operation of the HW platform under test.
USB interface functions as USB mass storage device during the test.
On-board memory is used as storage media which can be accessed from USB host PC
after successful enumeration of the device.
USB interface operates at high-speed (USB 2.0) during the test.

Test Accessories
"""""""""""""""""
USB cable

Test Setup
"""""""""""
Connect USB device port of the board to host PC.
Check below table for the details of USB device port used by the test on different platforms.

+---------------+-----------------+
| HW Platform   | USB Device Port |
+===============+=================+
| am65xx_evm    | J3 on CP board  |
+---------------+-----------------+
| am65xx_idk    | J3 on CP board  |
+---------------+-----------------+

Test Execution
"""""""""""""""
 - Select the menu option to run ‘usbDevice_TEST’
 - Verify the test log on serial console
 - Check the USB device enumeration on the host PC
 - Verify the data write/read access to new drive displayed on the host PC

Test Log
"""""""""""
Sample log for USB device test is shown below

::

    *********************************************
    *                 USB Device Test           *
    *********************************************

    Running USB Device test...

    USB device MSC Application!!

    Passed RAMDISKUtilsInit function

    Done configuring USB driver and its interrupts. Ready to use

|

USB Host Test
^^^^^^^^^^^^^^^^^^
This test verifies USB host mode operation of the HW platform under test.
USB interface functions as USB mass storage host during the test.
USB device connected to the board will be enumerated, a file will be created,
written with test data and read back to verify the data.
USB interface operates at high-speed (USB 2.0) during the test.

Test Accessories
"""""""""""""""""
USB OTG pen drive or normal USB pen drive with OTG cable

Test Setup
"""""""""""
Connect USB pen drive to host port of the board.
Check below table for the details of USB host port used by the test on different platforms.

+---------------+-----------------+
| HW Platform   | USB Host Port   |
+===============+=================+
| am65xx_evm    | J3 on CP board  |
+---------------+-----------------+
| am65xx_idk    | J3 on CP board. |
|               | J13 on SerDes   |
|               | board           |
+---------------+-----------------+

Test Execution
"""""""""""""""
 - Select the menu option to run ‘usbHost_TEST’
 - Test supports USB host port on CP board and SerDes board on AM65x IDK platform.
   Choose the board under test in the serial console while running the test on am65xx_idk
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for USB host test on am65xx_evm is shown below

::

    *************************************************
    *                  USB Host Test                *
    *************************************************

    USB Host MSC example!!

    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully

    USB Host test Passed

|

Sample log for USB host test on am65xx_idk CP board is shown below

::

    *************************************************
    *                  USB Host Test                *
    *************************************************

    USB Host MSC example!!

    Select the options below on which application has to be run

    1.CP board
    2.Serdes Board
    1
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully

    USB Host test Passed

|

Sample log for USB host test on am65xx_idk SerDes board is shown below

::

    *************************************************
    *                  USB Host Test                *
    *************************************************

    USB Host MSC example!!

    Select the options below on which application has to be run

    1.CP board
    2.Serdes Board
    2
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully

    USB Host test Passed

|

Stress Tests
-----------------
This section describes the test procedure and setup for diagnostic stress tests.
Stress test execution is done based on the type of interface as listed below

- Memory interfaces: Whole memory is accessed during stress test

- Communication interfaces (Ethernet, UART etc): Bulk data is sent during the
  stress test

- Control interfaces (On-board I2C, SPI, GPIO control interfaces): Functional
  test is repeated for 100 iterations

User confirmation for pass/fail status is disabled during the stress test.

Enter the character 'b' to break the stress test before it completes 100 iterations for control interfaces.
There is no option to break the stress test before completion in case of memory and communication interfaces.

Only partial logs are provided for stress tests for better readability.

Boot EEPROM Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies Boot EEPROM memory. All the pages of the EEPROM are written with
a test pattern and read back for data verification.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
Make sure pins 2-3 of J44 and J45 headers on AM65x CP board are shorted

Test Execution
"""""""""""""""
 - Select the menu option to run ‘bootEepromStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for boot EEPROM stress test is shown below

::

    *******************************************
    *           Boot EEPROM Stress Test       *
    *******************************************

    Verifying the Boot EEPROM interface under stress conditions...

    Verifying the page number - 0

    Verifying the page number - 1

    Verifying the page number - 2

    Verifying the page number - 3

    Verifying the page number - 4

    Verifying the page number - 5

    Verifying the page number - 6

    Verifying the page number - 7

    Verifying the page number - 8

    Verifying the page number - 9

    Verifying the page number - 10

    Verifying the page number - 11

    Verifying the page number - 12

    Verifying the page number - 13

    Verifying the page number - 14

    Verifying the page number - 15

    Verifying the page number - 16

    Verifying the page number - 17

    Verifying the page number - 18

    Verifying the page number - 19

    Verifying the page number - 20

    ...
    ...
    ...

    Verifying the page number - 500

    Verifying the page number - 501

    Verifying the page number - 502

    Verifying the page number - 503

    Verifying the page number - 504

    Verifying the page number - 505

    Verifying the page number - 506

    Verifying the page number - 507

    Verifying the page number - 508

    Verifying the page number - 509

    Verifying the page number - 510

    Verifying the page number - 511

    Boot EEPROM memory verification Successful under stress conditions

    Clearing the Boot EEPROM pages used for testing...

    Clearing the Boot EEPROM pages successful...

|

Current Monitor Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Test reads the voltage and current values from different current monitor devices available on the board.
All the current monitor devices available on the board are verified during the test.
Test is repeated for 100 iterations.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
For iceK2G, this test expects J16 and J17 to be connected with jumper
shunts. This enables the current monitors to be used.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘currentMonitorStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for current monitor stress test is shown below

::

    **********************************************
    *            Current Monitor Test            *
    **********************************************


    Running Current Monitor Test in Stress Mode for 100 Number of Times...


    Verifying Device VDD_CORE at Address - 0x40
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1003mV
    Reading the Power register...
    Power = 915mW
    Reading the Current register...
    Current = 11mA


    Verifying Device VDD_MCU at Address - 0x41
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 4mV
    Reading the Bus Voltage register...
    Bus Voltage = 998mV
    Reading the Power register...
    Power = 21282mW
    Reading the Current register...
    Current = 425mA


    Verifying Device VDD_MPU at Address - 0x42
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1002mV
    Reading the Power register...
    Power = 503mW
    Reading the Current register...
    Current = 7mA


    Verifying Device SoC_DVDD3V3 at Address - 0x43
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 3338mV
    Reading the Power register...
    Power = 2670mW
    Reading the Current register...
    Current = 18mA


    Verifying Device SoC_DVDD1V8 at Address - 0x44
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1800mV
    Reading the Power register...
    Power = 3204mW
    Reading the Current register...
    Current = 26mA


    Verifying Device SoC_AVDD1V8 at Address - 0x45
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 3mV
    Reading the Bus Voltage register...
    Bus Voltage = 1797mV
    Reading the Power register...
    Power = 15713mW
    Reading the Current register...
    Current = 70mA


    Verifying Device SoC_VDDS_DDR at Address - 0x46
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1197mV
    Reading the Power register...
    Power = 1388mW
    Reading the Current register...
    Current = 66mA


    Verifying Device VDD_DDR at Address - 0x47
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1198mV
    Reading the Power register...
    Power = 689mW
    Reading the Current register...
    Current = 10mA




    Iteration : 1 Current Monitor Test Passed

    ...
    ...
    ...


    Verifying Device VDD_CORE at Address - 0x40
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1003mV
    Reading the Power register...
    Power = 915mW
    Reading the Current register...
    Current = 12mA


    Verifying Device VDD_MCU at Address - 0x41
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 4mV
    Reading the Bus Voltage register...
    Bus Voltage = 998mV
    Reading the Power register...
    Power = 21282mW
    Reading the Current register...
    Current = 425mA


    Verifying Device VDD_MPU at Address - 0x42
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1002mV
    Reading the Power register...
    Power = 503mW
    Reading the Current register...
    Current = 7mA


    Verifying Device SoC_DVDD3V3 at Address - 0x43
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 3337mV
    Reading the Power register...
    Power = 2860mW
    Reading the Current register...
    Current = 18mA


    Verifying Device SoC_DVDD1V8 at Address - 0x44
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1800mV
    Reading the Power register...
    Power = 3204mW
    Reading the Current register...
    Current = 26mA


    Verifying Device SoC_AVDD1V8 at Address - 0x45
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 3mV
    Reading the Bus Voltage register...
    Bus Voltage = 1797mV
    Reading the Power register...
    Power = 15789mW
    Reading the Current register...
    Current = 70mA


    Verifying Device SoC_VDDS_DDR at Address - 0x46
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1198mV
    Reading the Power register...
    Power = 1388mW
    Reading the Current register...
    Current = 66mA


    Verifying Device VDD_DDR at Address - 0x47
    Setting the configuration register...
    Setting the calibration register...
    Reading the Shunt Voltage register...
    Shunt Voltage = 0mV
    Reading the Bus Voltage register...
    Bus Voltage = 1198mV
    Reading the Power register...
    Power = 689mW
    Reading the Current register...
    Current = 10mA




    Iteration : 100 Current Monitor Test Passed


    Current Monitor Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS

|

EMAC Stress Test
^^^^^^^^^^^^^^^^^
This test verifies the EMAC Ethernet port on HW platform under test.
Ethernet link and data transmit/receive are verified during this test.
Ethernet interface is configured for 100mbps speed and 10240 packets are sent/received during the test.

Test Accessories
""""""""""""""""""
Ethernet loopback cables/plugs

Test Setup
"""""""""""
Refer `EMAC Test Setup <index_board.html#id40>`_ section for more details

Test Execution
""""""""""""""""
 - Select the menu option to run ‘emacStress_TEST’
 - Verify the test log on serial console


Test Log
"""""""""

Sample log for Ethernet stress test is shown below

::

    ************************************************
    *      ETHERNET LOOPBACK STRESS Test           *
    ************************************************


    Reading Ethernet PHY Register Dump...
    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x7949
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x0300
    PHY Register 0x000a - 0x0c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077
    EMAC loopback test application initialization
    main: emac_open success
    Configuring Phy
    Waiting for Link Status
    Link is UP!!

    Sending Packet: 1
    Received Packet: 1
    Sending Packet: 2
    Received Packet: 2
    Sending Packet: 3
    Received Packet: 3
    Sending Packet: 4
    Received Packet: 4
    Sending Packet: 5
    Received Packet: 5
    Sending Packet: 6
    Received Packet: 6
    Sending Packet: 7
    Received Packet: 7
    Sending Packet: 8
    Received Packet: 8
    Sending Packet: 9
    Received Packet: 9
    Sending Packet: 10
    Received Packet: 10
    Sending Packet: 11
    Received Packet: 11
    Sending Packet: 12
    Received Packet: 12
    Sending Packet: 13
    Received Packet: 13
    Sending Packet: 14
    Received Packet: 14
    Sending Packet: 15
    Received Packet: 15
    Sending Packet: 16
    Received Packet: 16
    Sending Packet: 17
    Received Packet: 17
    Sending Packet: 18
    Received Packet: 18
    Sending Packet: 19
    Received Packet: 19
    Sending Packet: 20
    Received Packet: 20
    Sending Packet: 21
    Received Packet: 21
    Sending Packet: 22
    Received Packet: 22
    Sending Packet: 23
    Received Packet: 23
    Sending Packet: 24
    Received Packet: 24
    Sending Packet: 25
    Received Packet: 25
    Sending Packet: 26
    Received Packet: 26
    Sending Packet: 27
    Received Packet: 27
    Sending Packet: 28
    Received Packet: 28
    Sending Packet: 29
    Received Packet: 29
    Sending Packet: 30
    Received Packet: 30
    Sending Packet: 31
    Received Packet: 31
    Sending Packet: 32
    Received Packet: 32
    Sending Packet: 33
    Received Packet: 33
    Sending Packet: 34
    Received Packet: 34
    Sending Packet: 35
    Received Packet: 35
    Sending Packet: 36
    Received Packet: 36
    Sending Packet: 37
    Received Packet: 37
    Sending Packet: 38
    Received Packet: 38
    Sending Packet: 39
    Received Packet: 39
    Sending Packet: 40
    Received Packet: 40
    Sending Packet: 41
    Received Packet: 41
    Sending Packet: 42
    Received Packet: 42
    Sending Packet: 43
    Received Packet: 43
    Sending Packet: 44
    Received Packet: 44
    Sending Packet: 45
    Received Packet: 45
    Sending Packet: 46
    Received Packet: 46
    Sending Packet: 47
    Received Packet: 47
    Sending Packet: 48
    Received Packet: 48
    Sending Packet: 49
    Received Packet: 49
    Sending Packet: 50
    Received Packet: 50
    Sending Packet: 51
    Received Packet: 51
    Sending Packet: 52
    Received Packet: 52
    Sending Packet: 53
    Received Packet: 53
    Sending Packet: 54
    Received Packet: 54
    Sending Packet: 55
    Received Packet: 55
    Sending Packet: 56
    Received Packet: 56
    Sending Packet: 57
    Received Packet: 57
    Sending Packet: 58
    Received Packet: 58
    Sending Packet: 59
    Received Packet: 59
    Sending Packet: 60
    Received Packet: 60
    Sending Packet: 61
    Received Packet: 61
    Sending Packet: 62
    Received Packet: 62
    Sending Packet: 63
    Received Packet: 63
    Sending Packet: 64
    Received Packet: 64

    ...
    ...
    ...

    Sending Packet: 10200
    Received Packet: 10200
    Sending Packet: 10201
    Received Packet: 10201
    Sending Packet: 10202
    Received Packet: 10202
    Sending Packet: 10203
    Received Packet: 10203
    Sending Packet: 10204
    Received Packet: 10204
    Sending Packet: 10205
    Received Packet: 10205
    Sending Packet: 10206
    Received Packet: 10206
    Sending Packet: 10207
    Received Packet: 10207
    Sending Packet: 10208
    Received Packet: 10208
    Sending Packet: 10209
    Received Packet: 10209
    Sending Packet: 10210
    Received Packet: 10210
    Sending Packet: 10211
    Received Packet: 10211
    Sending Packet: 10212
    Received Packet: 10212
    Sending Packet: 10213
    Received Packet: 10213
    Sending Packet: 10214
    Received Packet: 10214
    Sending Packet: 10215
    Received Packet: 10215
    Sending Packet: 10216
    Received Packet: 10216
    Sending Packet: 10217
    Received Packet: 10217
    Sending Packet: 10218
    Received Packet: 10218
    Sending Packet: 10219
    Received Packet: 10219
    Sending Packet: 10220
    Received Packet: 10220
    Sending Packet: 10221
    Received Packet: 10221
    Sending Packet: 10222
    Received Packet: 10222
    Sending Packet: 10223
    Received Packet: 10223
    Sending Packet: 10224
    Received Packet: 10224
    Sending Packet: 10225
    Received Packet: 10225
    Sending Packet: 10226
    Received Packet: 10226
    Sending Packet: 10227
    Received Packet: 10227
    Sending Packet: 10228
    Received Packet: 10228
    Sending Packet: 10229
    Received Packet: 10229
    Sending Packet: 10230
    Received Packet: 10230
    Sending Packet: 10231
    Received Packet: 10231
    Sending Packet: 10232
    Received Packet: 10232
    Sending Packet: 10233
    Received Packet: 10233
    Sending Packet: 10234
    Received Packet: 10234
    Sending Packet: 10235
    Received Packet: 10235
    Sending Packet: 10236
    Received Packet: 10236
    Sending Packet: 10237
    Received Packet: 10237
    Sending Packet: 10238
    Received Packet: 10238
    Sending Packet: 10239
    Received Packet: 10239
    Sending Packet: 10240
    Received Packet: 10240

    Packets sent: 10240, Packets received: 10240

    Ethernet Loopback test passed
    All tests completed

|

eMMC Stress Test
^^^^^^^^^^^^^^^^
This test verifies eMMC memory interface on the HW platform under test.
Whole memory of eMMC is written and read during the test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘emmcStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for eMMC stress test is shown below

::

    *********************************************
    *                 eMMC Stress Test            *
    ***********************************************

    PASS: Read/Write Success for this block-0x300000

    PASS: Read/Write Success for this block-0x301000

    PASS: Read/Write Success for this block-0x302000

    PASS: Read/Write Success for this block-0x303000

    PASS: Read/Write Success for this block-0x304000

    PASS: Read/Write Success for this block-0x305000

    PASS: Read/Write Success for this block-0x306000

    PASS: Read/Write Success for this block-0x307000

    PASS: Read/Write Success for this block-0x308000

    PASS: Read/Write Success for this block-0x309000

    PASS: Read/Write Success for this block-0x30a000

    PASS: Read/Write Success for this block-0x30b000

    PASS: Read/Write Success for this block-0x30c000

    PASS: Read/Write Success for this block-0x30d000

    PASS: Read/Write Success for this block-0x30e000

    PASS: Read/Write Success for this block-0x30f000

    ...
    ...
    ...

    PASS: Read/Write Success for this block-0x1d55000

    PASS: Read/Write Success for this block-0x1d56000

    PASS: Read/Write Success for this block-0x1d57000

    PASS: Read/Write Success for this block-0x1d58000

    PASS: Read/Write Success for this block-0x1d59000

    PASS: Read/Write Success for this block-0x1d5a000

    PASS: Read/Write Success for this block-0x1d5b000

    PASS: Read/Write Success for this pattern
|

External RTC Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies setting the time, date and running the clock for on-board RTC interface.
RTC configuration is done through I2C interface. Time and date are read for 100 times for every 5secs
during the test to demonstrate operation of the RTC clock.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘extRtcStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for external RTC stress test is shown below

::

    *********************************************
    *                 RTC Test                  *
    *********************************************
    Running RTC Test in Stress Mode for 100 Number of Times...
    Enter 'b' in Serial Console to Terminate the Test


    Running RTC Test...

    Setting Time...

    Setting Date...

    Reading Time...

    Reading Date...


    Displaying time: 11:59:53 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 11:59:57 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 12:0:2 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:7 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:12 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:17 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19
    If the time and date increment, press 'y' to indicate pass or any other character to indicate failure


    Iteration : 1 RTC Test Passed

    Running RTC Test...

    Setting Time...

    Setting Date...

    Reading Time...

    Reading Date...


    Displaying time: 11:59:53 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 11:59:58 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 12:0:3 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:8 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:14 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:19 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19
    If the time and date increment, press 'y' to indicate pass or any other character to indicate failure


    Iteration : 2 RTC Test Passed

    ...
    ...
    ...

    Running RTC Test...

    Setting Time...

    Setting Date...

    Reading Time...

    Reading Date...


    Displaying time: 11:59:53 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 11:59:58 PM
    Displaying  Day: Sunday
    Displaying Date: 31/12/18

    Displaying time: 12:0:3 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:8 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:13 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19

    Displaying time: 12:0:18 AM
    Displaying  Day: Monday
    Displaying Date: 1/1/19
    If the time and date increment, press 'y' to indicate pass or any other character to indicate failure


    Iteration : 100 RTC Test Passed
    RTC Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS

    RTC Test Passed

|

ICSSG EMAC Stress Test
^^^^^^^^^^^^^^^^^^^^^^^
This port to port Ethernet test verifies the PRU-ICSS gigabit Ethernet interface on the board under test.
During the test, Ethernet interface is configured for 1000mbps speed with one port of an ICSS instance
is connected to another port. 10240 packets are sent from one port and received by another port.
Both the ports are verified for transmit and receive. All the ICSSG EMAC ports available on the board
verified during the test.

Test Accessories
""""""""""""""""""
Ethernet cables

Test Setup
""""""""""""
Refer `ICSSG EMAC Test Setup <index_board.html#id68>`_ section for more details

Test Execution
""""""""""""""""
 - Select the menu option to run ‘icssgEmacStress_TEST’
 - Verify the test log on serial console


Test Log
""""""""""

Sample log for ICSGG Ethernet stress test is shown below

::

    **********************************************
    *           ICSSG EMAC STRESS TEST           *
    **********************************************


    Performing UDMA driver init...


    Reading Ethernet PHY Register Dump...


    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x1b00
    PHY Register 0x000a - 0x7c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Configuration Register(CFG4) 0x0031 - 0xbf02
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0003
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x1300
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Configuration Register(CFG4) 0x0031 - 0xbd02
    PHY Register(STRAP1) 0x006e - 0x0003
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x1b00
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Configuration Register(CFG4) 0x0031 - 0xbd02
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0003
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x1300
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Configuration Register(CFG4) 0x0031 - 0xbe02
    PHY Register(STRAP1) 0x006e - 0x0003
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0000
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x1b00
    PHY Register 0x000a - 0x7c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Configuration Register(CFG4) 0x0031 - 0xbc02
    PHY Register(STRAP1) 0x006e - 0x0000
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077


    Register Dump for PHY Addr - 0x0003
    PHY Register 0x0000 - 0x1140
    PHY Register 0x0001 - 0x796d
    PHY Register 0x0002 - 0x2000
    PHY Register 0x0003 - 0xa231
    PHY Register 0x0004 - 0x01e1
    PHY Register 0x0005 - 0xc1e1
    PHY Register 0x0006 - 0x006f
    PHY Register 0x0007 - 0x2001
    PHY Register 0x0008 - 0x4806
    PHY Register 0x0009 - 0x1300
    PHY Register 0x000a - 0x3c00
    PHY Register 0x000b - 0x0000
    PHY Register 0x000c - 0x0000
    PHY Register 0x000d - 0x401f
    PHY Register 0x000e - 0x0006
    PHY Register 0x000f - 0x3000
    PHY Configuration Register(CFG4) 0x0031 - 0xbc02
    PHY Register(STRAP1) 0x006e - 0x0003
    PHY Register(STRAP2) 0x006f - 0x0000
    RGMII Control Register (RGMIICTL) Value - 0x00d3
      --- RGMII_RX_CLK_DELAY - 0x0001
      --- RGMII_TX_CLK_DELAY - 0x0001
    RGMII Delay Control Register (RGMIIDCTL) Value - 0x0077
    port 0:  FW is ready
    Port 0:  Config FW Complete
    port 1:  FW is ready
    Port 1:  Config FW Complete
    port 2:  FW is ready
    Port 2:  Config FW Complete
    port 3:  FW is ready
    Port 3:  Config FW Complete
    port 4:  FW is ready
    Port 4:  Config FW Complete
    port 5:  FW is ready
    Port 5:  Config FW Complete

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 0 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 1 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 2 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 3 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 4 LINK IS UP!

    EMAC loopback test application initialization
    main: emac_open success


    Waiting for LINK UP, Make sure to plugin loopback cable
    PRU_ICSS port 5 LINK IS UP!


    Sending Packets on Port - 0
    Receiving Packets on Port - 1

    Sending Packet: 1
    Received Packet: 1
    Sending Packet: 2
    Received Packet: 2
    Sending Packet: 3
    Received Packet: 3
    Sending Packet: 4
    Received Packet: 4
    Sending Packet: 5
    Received Packet: 5
    Sending Packet: 6
    Received Packet: 6
    Sending Packet: 7
    Received Packet: 7
    Sending Packet: 8
    Received Packet: 8
    Sending Packet: 9
    Received Packet: 9
    Sending Packet: 10
    Received Packet: 10
    Sending Packet: 11
    Received Packet: 11
    Sending Packet: 12
    Received Packet: 12
    Sending Packet: 13
    Received Packet: 13
    Sending Packet: 14
    Received Packet: 14
    Sending Packet: 15
    Received Packet: 15
    Sending Packet: 16
    Received Packet: 16

    ...
    ...
    ...

    Sending Packet: 10236
    Received Packet: 10236
    Sending Packet: 10237
    Received Packet: 10237
    Sending Packet: 10238
    Received Packet: 10238
    Sending Packet: 10239
    Received Packet: 10239
    Sending Packet: 10240
    Received Packet: 10240

    Packets Sent: 10240, Packets Received: 10240
    Port 0 Send to Port 1 Receive Test Passed!

    Sending Packets on Port - 1
    Receiving Packets on Port - 0
    Sending Packet: 1
    Received Packet: 1
    Sending Packet: 2
    Received Packet: 2
    Sending Packet: 3
    Received Packet: 3
    Sending Packet: 4
    Received Packet: 4
    Sending Packet: 5
    Received Packet: 5
    Sending Packet: 6
    Received Packet: 6
    Sending Packet: 7
    Received Packet: 7
    Sending Packet: 8
    Received Packet: 8
    Sending Packet: 9
    Received Packet: 9
    Sending Packet: 10
    Received Packet: 10
    Sending Packet: 11
    Received Packet: 11
    Sending Packet: 12
    Received Packet: 12
    Sending Packet: 13
    Received Packet: 13
    Sending Packet: 14
    Received Packet: 14
    Sending Packet: 15
    Received Packet: 15
    Sending Packet: 16
    Received Packet: 16

    ...
    ...
    ...

    Sending Packet: 10236
    Received Packet: 10236
    Sending Packet: 10237
    Received Packet: 10237
    Sending Packet: 10238
    Received Packet: 10238
    Sending Packet: 10239
    Received Packet: 10239
    Sending Packet: 10240
    Received Packet: 10240

    Packets Sent: 10240, Packets Received: 10240
    Port 1 Send to Port 0 Receive Test Passed!

    Sending Packets on Port - 2
    Receiving Packets on Port - 3

    Sending Packet: 1
    Received Packet: 1
    Sending Packet: 2
    Received Packet: 2
    Sending Packet: 3
    Received Packet: 3
    Sending Packet: 4
    Received Packet: 4
    Sending Packet: 5
    Received Packet: 5
    Sending Packet: 6
    Received Packet: 6
    Sending Packet: 7
    Received Packet: 7
    Sending Packet: 8
    Received Packet: 8
    Sending Packet: 9
    Received Packet: 9
    Sending Packet: 10
    Received Packet: 10
    Sending Packet: 11
    Received Packet: 11
    Sending Packet: 12
    Received Packet: 12
    Sending Packet: 13
    Received Packet: 13
    Sending Packet: 14
    Received Packet: 14
    Sending Packet: 15
    Received Packet: 15
    Sending Packet: 16
    Received Packet: 16

    ...
    ...
    ...

    Sending Packet: 10236
    Received Packet: 10236
    Sending Packet: 10237
    Received Packet: 10237
    Sending Packet: 10238
    Received Packet: 10238
    Sending Packet: 10239
    Received Packet: 10239
    Sending Packet: 10240
    Received Packet: 10240

    Packets Sent: 10240, Packets Received: 10240
    Port 2 Send to Port 3 Receive Test Passed!

    Sending Packets on Port - 3
    Receiving Packets on Port - 2
    Sending Packet: 1
    Received Packet: 1
    Sending Packet: 2
    Received Packet: 2
    Sending Packet: 3
    Received Packet: 3
    Sending Packet: 4
    Received Packet: 4
    Sending Packet: 5
    Received Packet: 5
    Sending Packet: 6
    Received Packet: 6
    Sending Packet: 7
    Received Packet: 7
    Sending Packet: 8
    Received Packet: 8
    Sending Packet: 9
    Received Packet: 9
    Sending Packet: 10
    Received Packet: 10
    Sending Packet: 11
    Received Packet: 11
    Sending Packet: 12
    Received Packet: 12
    Sending Packet: 13
    Received Packet: 13
    Sending Packet: 14
    Received Packet: 14
    Sending Packet: 15
    Received Packet: 15
    Sending Packet: 16
    Received Packet: 16

    ...
    ...
    ...

    Sending Packet: 10236
    Received Packet: 10236
    Sending Packet: 10237
    Received Packet: 10237
    Sending Packet: 10238
    Received Packet: 10238
    Sending Packet: 10239
    Received Packet: 10239
    Sending Packet: 10240
    Received Packet: 10240

    Packets Sent: 10240, Packets Received: 10240
    Port 2 Send to Port 3 Receive Test Passed!

    ...
    ...
    ...

    Sending Packets on Port - 5
    Receiving Packets on Port - 4
    Sending Packet: 1
    Received Packet: 1
    Sending Packet: 2
    Received Packet: 2
    Sending Packet: 3
    Received Packet: 3
    Sending Packet: 4
    Received Packet: 4
    Sending Packet: 5
    Received Packet: 5
    Sending Packet: 6
    Received Packet: 6
    Sending Packet: 7
    Received Packet: 7
    Sending Packet: 8
    Received Packet: 8
    Sending Packet: 9
    Received Packet: 9
    Sending Packet: 10
    Received Packet: 10
    Sending Packet: 11
    Received Packet: 11
    Sending Packet: 12
    Received Packet: 12
    Sending Packet: 13
    Received Packet: 13
    Sending Packet: 14
    Received Packet: 14
    Sending Packet: 15
    Received Packet: 15
    Sending Packet: 16
    Received Packet: 16

    ...
    ...
    ...

    Sending Packet: 10236
    Received Packet: 10236
    Sending Packet: 10237
    Received Packet: 10237
    Sending Packet: 10238
    Received Packet: 10238
    Sending Packet: 10239
    Received Packet: 10239
    Sending Packet: 10240
    Received Packet: 10240

    Packets Sent: 10240, Packets Received: 10240
    Port 5 Send to Port 4 Receive Test Passed!


    ICSSG Ethernet Port to Port Test Passed!
    All Tests Completed

|

ICSS LED Stress Test
^^^^^^^^^^^^^^^^^^^^^
This test verifies LEDs connected to PRU-ICSS ports.
All the LEDs are turned ON and OFF for 3 times during the test.
Test is repeated for 100 iterations.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.


Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘icssgLedStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for ICSS LED stress test is shown below

::

    Running ICSSG LED Test in Stress Mode for 100 Number of Times...
    Enter 'b' in Serial Console to Terminate the Test


    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 1 ICSSG LED Test Passed

    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 2 ICSSG LED Test Passed

    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 3 ICSSG LED Test Passed

    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 4 ICSSG LED Test Passed

    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 5 ICSSG LED Test Passed

    ...
    ...
    ...

    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 99 ICSSG LED Test Passed

    ********************************************
    *              ICSS LED Test               *
    ********************************************

    Testing ICSSG PRG0 and PRG1 LED's
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 100 ICSSG LED Test Passed


    ICSSG LED Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS

|

Industrial LED Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies industrial LEDs connected to I2C interface on the HW platform under test.
All the LEDs are turned ON and OFF for 3 times during the test.
Test is repeated for 100 iterations.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘ledIndustrialStress_TEST’
 - Confirm that all the industrial LEDs on the board are toggling during the test
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for industrial LED stress test is shown below

::

    *********************************************
    *            Industrial LED Test            *
    *********************************************


    Running Industrial Test in Stress Mode for 100 Number of Times...
    Enter 'b' in Serial Console to Terminate the Test


    Running Industrial Test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!

    Testing Industrial LEDs on AM65xx IDK Board
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 1 Industrial Test Passed

    Running Industrial Test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!

    Testing Industrial LEDs on AM65xx IDK Board
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 2 Industrial Test Passed

    Running Industrial Test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!

    Testing Industrial LEDs on AM65xx IDK Board
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 3 Industrial Test Passed

    Running Industrial Test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!

    Testing Industrial LEDs on AM65xx IDK Board
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 4 Industrial Test Passed

    ...
    ...
    ...

    Running Industrial Test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!

    Testing Industrial LEDs on AM65xx IDK Board
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 99 Industrial Test Passed

    Running Industrial Test...
    Verifying LED's connected to I2C IO Expander target device...

    Testing Industrial LEDs
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!

    Testing Industrial LEDs on AM65xx IDK Board
    Cycling LEDs 3 times
    Press 'y' to verify pass, 'r' to cycle leds again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 100 Industrial Test Passed

    Industrial Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS

|

LED Stress Test
^^^^^^^^^^^^^^^^
This test verifies general purpose user LEDs on the HW platform under test.
All the LEDs are turned ON and OFF for 3 times during the test.
Test is repeated for 100 iterations.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘ledStress_TEST’
 - Confirm that all the general purpose user LEDs on the board are toggling during the test
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for LED stress test is shown below

::

    Running LED Test in Stress Mode for 100 Number of Times...
    Enter 'b' in Serial Console to Terminate the Test


    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 1 LED Test Passed

    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 2 LED Test Passed

    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 3 LED Test Passed

    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 4 LED Test Passed

    ...
    ...
    ...

    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 99 LED Test Passed

    *********************************************
    *                 LED Test                  *
    *********************************************

    Testing LED
    Blinking LEDs...
    Press 'y' to verify pass, 'r' to blink again,
    or any other character to indicate failure: Received: y

    Test PASSED!




    Iteration : 100 LED Test Passed


    LED Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS

|

Memory (DDR) Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies the DDR memory of the HW platform under test.
Address bus test is performed with a test pattern and its compliment during the test.
Walking 1s and walking 0s test is executed additionally as part of stress test.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘memStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""

Sample DDR stress test log is shown below

::

    *********************************************
    *              DDR Memory Test              *
    *********************************************

    Testing writing and reading memory
    board_external_memory_test: Start address (0x80000000),            end address (0xffffffff)
    First test started
    Writing to test area...
            Write up to 0x80000000 done
            Write up to 0x90000000 done
            Write up to 0xa0000000 done
            Write up to 0xb0000000 done
            Write up to 0xc0000000 done
            Write up to 0xd0000000 done
            Write up to 0xe0000000 done
            Write up to 0xf0000000 done
    Write finished!
    Checking values...
            Read up to 0x80000000 okay
            Read up to 0x90000000 okay
            Read up to 0xa0000000 okay
            Read up to 0xb0000000 okay
            Read up to 0xc0000000 okay
            Read up to 0xd0000000 okay
            Read up to 0xe0000000 okay
            Read up to 0xf0000000 okay
    Second test started
    Writing complementary values to test area...
            Write up to 0x80000000 done
            Write up to 0x90000000 done
            Write up to 0xa0000000 done
            Write up to 0xb0000000 done
            Write up to 0xc0000000 done
            Write up to 0xd0000000 done
            Write up to 0xe0000000 done
            Write up to 0xf0000000 done
    Write finished!
    Checking values...
            Read up to 0x80000000 okay
            Read up to 0x90000000 okay
            Read up to 0xa0000000 okay
            Read up to 0xb0000000 okay
            Read up to 0xc0000000 okay
            Read up to 0xd0000000 okay
            Read up to 0xe0000000 okay
            Read up to 0xf0000000 okay
    Board memory test passed!
             walking1s test verified up to 0x80000000      done
             walking1s test verified up to 0x90000000      done
             walking1s test verified up to 0xa0000000      done
             walking1s test verified up to 0xb0000000      done
             walking1s test verified up to 0xc0000000      done
             walking1s test verified up to 0xd0000000      done
             walking1s test verified up to 0xe0000000      done
             walking1s test verified up to 0xf0000000      done
    walking1s test passed!
             walking0s test verified up to 0x80000000      done
             walking0s test verified up to 0x90000000      done
             walking0s test verified up to 0xa0000000      done
             walking0s test verified up to 0xb0000000      done
             walking0s test verified up to 0xc0000000      done
             walking0s test verified up to 0xd0000000      done
             walking0s test verified up to 0xe0000000      done
             walking0s test verified up to 0xf0000000      done
    walking0s test passed!
    Memory test passed!

|

MMCSD Stress Test
^^^^^^^^^^^^^^^^^^
This test verifies SD card interface on the platform under test.
Whole memory of SD card starting from 1.5GB offset is written and read during the test.

Test Accessories
"""""""""""""""""
SD card.

Test Setup
"""""""""""
Insert the SD card into MMCSD slot of the board.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘mmcsdStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for SD card stress test is shown below

::

    *********************************************
    *                 MMCSD Stress Test         *
    *********************************************

    PASS: Read/Write Success for this block-0x300000

    PASS: Read/Write Success for this block-0x301000

    PASS: Read/Write Success for this block-0x302000

    PASS: Read/Write Success for this block-0x303000

    PASS: Read/Write Success for this block-0x304000

    PASS: Read/Write Success for this block-0x305000

    PASS: Read/Write Success for this block-0x306000

    PASS: Read/Write Success for this block-0x307000

    PASS: Read/Write Success for this block-0x308000

    PASS: Read/Write Success for this block-0x309000

    PASS: Read/Write Success for this block-0x30a000

    PASS: Read/Write Success for this block-0x30b000

    PASS: Read/Write Success for this block-0x30c000

    PASS: Read/Write Success for this block-0x30d000

    PASS: Read/Write Success for this block-0x30e000

    PASS: Read/Write Success for this block-0x30f000

    PASS: Read/Write Success for this block-0x310000

    ...
    ...
    ...

    PASS: Read/Write Success for this block-0x5fa000

    PASS: Read/Write Success for this block-0x5fb000

    PASS: Read/Write Success for this block-0x5fc000

    PASS: Read/Write Success for this block-0x5fd000

    PASS: Read/Write Success for this block-0x5fe000

    PASS: Read/Write Success for this block-0x5ff000

    PASS: Read/Write Success for this pattern

|

NOR Flash Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies the NOR flash memory connected to SPI interface.
Whole memory of flash is written and read back for data verification during the test.


Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘norflashStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for NOR flash stress test is shown below

::

    ************************************************
    *            SPI FlASH Stress Test             *
    ************************************************
    Reading Flash Device ID...
    Device ID 0 - 0x20
    Device ID 1 - 0xba
    Device ID 2 - 0x18
    Flash Device ID Match!

    Flash Device ID Read Passed!

    Verifying Sector - 0
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 1
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 2
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 3
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 4
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 5
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 6
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 7
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 8
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 9
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 10
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 11
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 12
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 13
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 14
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 15
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 16
    Data Read matches with Data written
    SPI Flash Test Passed!

    ...
    ...
    ...

    Verifying Sector - 250
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 251
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 252
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 253
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 254
    Data Read matches with Data written
    SPI Flash Test Passed!

    Verifying Sector - 255
    Data Read matches with Data written
    SPI Flash Test Passed!

    SPI NOR Flash Test Passed

|

OSPI Flash Stress Test
^^^^^^^^^^^^^^^^^^^^^^^
This test verifies the flash memory connected to OSPI interface.
Whole memory of OSPI flash is written and read back for data verification during the test.


Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘ospiStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for OSPI flash stress test is shown below

::

    ****************************************************
    *            OSPI FLASH Stress Test                *
    ****************************************************

    OSPI NOR device ID: 0x5b1a, manufacturer ID: 0x2c

    Verifying the OSPI Flash ...

    OSPI Flash Stress Test Iteration - 1

    Verified upto Page - 0x0

    Verified upto Page - 0x1000

    Verified upto Page - 0x2000

    Verified upto Page - 0x3000

    Verified upto Page - 0x4000

    Verified upto Page - 0x5000

    Verified upto Page - 0x6000

    Verified upto Page - 0x7000

    Verified upto Page - 0x8000

    Verified upto Page - 0x9000

    Verified upto Page - 0xa000

    Verified upto Page - 0xb000

    Verified upto Page - 0xc000

    Verified upto Page - 0xd000

    Verified upto Page - 0xe000

    Verified upto Page - 0xf000

    ...
    ...
    ...

    Verified upto Page - 0x3ffd000

    Verified upto Page - 0x3ffe000

    Verified upto Page - 0x3fff000

    OSPI NOR Flash verification Successful

|

Temperature Sensor Stress Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This test verifies reading the ambient temperature from temperature sensor interface.
Test verifies all the temperature sensor devices on the board.
Test is repeated for 100 iterations.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
 - Select the menu option to run ‘temperatureStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for temperature sensor stress test is shown below

::

    *********************************************
    *          Temperature Sensor Test          *
    *********************************************


    Running Temperature Sensor Test in Stress Mode for 100 Number of Times...
    Enter 'b' in Serial Console to Terminate the Test


    Running Temperature Sensor Test...
    Running temperature sensor test...
    Read temperature register value - 680

    Temperature read from the temperature sensor
     target address - 0x48 is 42 degree centigrade
    Read temperature register value - 616

    Temperature read from the temperature sensor
     target address - 0x49 is 38 degree centigrade
    Temperature sensor test Passed!




    Iteration : 1 Temperature Sensor Test Passed

    Running Temperature Sensor Test...
    Running temperature sensor test...
    Read temperature register value - 680

    Temperature read from the temperature sensor
     target address - 0x48 is 42 degree centigrade
    Read temperature register value - 616

    Temperature read from the temperature sensor
     target address - 0x49 is 38 degree centigrade
    Temperature sensor test Passed!




    Iteration : 2 Temperature Sensor Test Passed

    Running Temperature Sensor Test...
    Running temperature sensor test...
    Read temperature register value - 680

    Temperature read from the temperature sensor
     target address - 0x48 is 42 degree centigrade
    Read temperature register value - 616

    Temperature read from the temperature sensor
     target address - 0x49 is 38 degree centigrade
    Temperature sensor test Passed!




    Iteration : 3 Temperature Sensor Test Passed

    Running Temperature Sensor Test...
    Running temperature sensor test...
    Read temperature register value - 680

    Temperature read from the temperature sensor
     target address - 0x48 is 42 degree centigrade
    Read temperature register value - 616

    Temperature read from the temperature sensor
     target address - 0x49 is 38 degree centigrade
    Temperature sensor test Passed!




    Iteration : 4 Temperature Sensor Test Passed

    ...
    ...
    ...

    Running Temperature Sensor Test...
    Running temperature sensor test...
    Read temperature register value - 680

    Temperature read from the temperature sensor
     target address - 0x48 is 42 degree centigrade
    Read temperature register value - 616

    Temperature read from the temperature sensor
     target address - 0x49 is 38 degree centigrade
    Temperature sensor test Passed!




    Iteration : 99 Temperature Sensor Test Passed

    Running Temperature Sensor Test...
    Running temperature sensor test...
    Read temperature register value - 680

    Temperature read from the temperature sensor
     target address - 0x48 is 42 degree centigrade
    Read temperature register value - 616

    Temperature read from the temperature sensor
     target address - 0x49 is 38 degree centigrade
    Temperature sensor test Passed!




    Iteration : 100 Temperature Sensor Test Passed

    Temperature Sensor Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS



    Temperature Sensor Test Passed
|

USB Host Stress Test
^^^^^^^^^^^^^^^^^^^^^
This test verifies USB host mode operation of the HW platform under test.
USB interface functions as USB mass storage host during the test.
USB device connected to the board will be enumerated, a file will be created,
written with test data and read back to verify the data.
USB interface operates at high-speed (USB 2.0) during the test.
Test is repeated for 100 iterations.

Test Accessories
"""""""""""""""""
USB OTG pen drive or normal pen drive with OTG cable

Test Setup
"""""""""""
Refer `USB Host Test Setup <index_board.html#id188>`_ section for more details

Test Execution
"""""""""""""""
 - Select the menu option to run ‘usbHostStress_TEST’
 - Test supports USB host port on CP board and SerDes board on AM65x IDK platform.
   Choose the board under test in the serial console while running the test on am65xx_idk
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for USB host stress test on am65xx_evm is shown below

::

    *************************************************
    *                  USB Host Test                *
    *************************************************

    USB Host MSC example!!



    Running USB Host Test in Stress Mode for 100 Number of Times...
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 1 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 2 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 3 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 4 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 5 USB Host Test Passed

    ...
    ...
    ...

    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 99 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 100 USB Host Test Passed


    USB Host Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS



    USB Host test Passed

|

Sample log for USB host stress test on am65xx_idk board is shown below

::

    *************************************************
    *                  USB Host Test                *
    *************************************************

    USB Host MSC example!!

    Select the options below on which application has to be run

    1.CP board
    2.Serdes Board
    1


    Running USB Host Test in Stress Mode for 100 Number of Times...
    Enter 'b' in Serial Console to Terminate the Test

    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 1 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 2 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 3 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 4 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 5 USB Host Test Passed

    ...
    ...
    ...

    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 99 USB Host Test Passed
    Creating a text file...
    File already exist..!, deleting existing file and creating a new file

    Successfully created text file!
    Verifying data......
    Data verified successfully




    Iteration : 100 USB Host Test Passed


    USB Host Stress Test Status
    ===================================
    Number of Times Executed - 100
    Pass Count - 100
    Fail Count - 0
    Overall Status - PASS

|

MCAN Stress Test
^^^^^^^^^^^^^^^^^
Verifies MCAN ports on the HW platform with two MCAN ports connected with each other.
10240 packets sent from one port and received on another port. Both the ports are verified for Tx and Rx.

Test Accessories
"""""""""""""""""
MCAN port to port loopback cable

Test Setup
"""""""""""
Refer `MCAN Test Setup <index_board.html#id96>`_ section for more details

Test Execution
"""""""""""""""
 - Select the menu option to run ‘mcanStress_TEST’
 - Verify the test log on serial console

Test Log
"""""""""""
Sample log for MCAN stress test is shown below

::

    ***********************************************
    *                MCAN Stress Test             *
    ***********************************************
    MCANSS Revision ID:
    scheme:0x1
    Business Unit:0x2
    Module ID:0x8e0
    RTL Revision:0x5
    Major Revision:0x1
    Custom Revision:0x0
    Minor Revision:0x1
    CAN-FD operation is enabled through E-Fuse.
    Endianess Value:0x87654321
    Successfully configured MCAN0
    MCANSS Revision ID:
    scheme:0x1
    Business Unit:0x2
    Module ID:0x8e0
    RTL Revision:0x5
    Major Revision:0x1
    Custom Revision:0x0
    Minor Revision:0x1
    CAN-FD operation is enabled through E-Fuse.
    Endianess Value:0x87654321
    Successfully configured MCAN1


    Transmitting Data on MCAN Port0 and Receiving on MCAN port 1

    Sending Packet - 1

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0x30

    Message DataByte2:0xb9

    Message DataByte3:0xd6

    Message DataByte4:0xfb

    Message DataByte5:0x4b

    Message DataByte6:0x87

    Message DataByte7:0x27

    Message DataByte8:0x97

    Message DataByte9:0x58

    Message DataByte10:0x0

    Message DataByte11:0xc0

    Message DataByte12:0xd4

    Message DataByte13:0xe

    Message DataByte14:0x3

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x100008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0x30

    Message DataByte2:0xb9

    Message DataByte3:0xd6

    Message DataByte4:0xfb

    Message DataByte5:0x4b

    Message DataByte6:0x87

    Message DataByte7:0x27

    Message DataByte8:0x97

    Message DataByte9:0x58

    Message DataByte10:0x0

    Message DataByte11:0xc0

    Message DataByte12:0xd4

    Message DataByte13:0xe

    Message DataByte14:0x3

    Received Packet - 1

    ...
    ...
    ...

    Sending Packet - 10240

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0x59

    Message DataByte2:0x2a

    Message DataByte3:0x5b

    Message DataByte4:0x4b

    Message DataByte5:0x9e

    Message DataByte6:0xd1

    Message DataByte7:0x77

    Message DataByte8:0x9d

    Message DataByte9:0x46

    Message DataByte10:0x6d

    Message DataByte11:0x74

    Message DataByte12:0xd7

    Message DataByte13:0xc2

    Message DataByte14:0x8d

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0x59

    Message DataByte2:0x2a

    Message DataByte3:0x5b

    Message DataByte4:0x4b

    Message DataByte5:0x9e

    Message DataByte6:0xd1

    Message DataByte7:0x77

    Message DataByte8:0x9d

    Message DataByte9:0x46

    Message DataByte10:0x6d

    Message DataByte11:0x74

    Message DataByte12:0xd7

    Message DataByte13:0xc2

    Message DataByte14:0x8d

    Received Packet - 10240



    Transmitting Data on MCAN Port1 and Receiving on MCAN port 0

    Sending Packet - 1

    Message successfully transferred with payload Bytes:0xf
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0x1f

    Message DataByte2:0x44

    Message DataByte3:0x40

    Message DataByte4:0x68

    Message DataByte5:0x7a

    Message DataByte6:0x5d

    Message DataByte7:0xf5

    Message DataByte8:0x3e

    Message DataByte9:0xa5

    Message DataByte10:0xb7

    Message DataByte11:0xe3

    Message DataByte12:0x36

    Message DataByte13:0x3a

    Message DataByte14:0x76

    Received Packet - 1

    ...
    ...
    ...

    Sending Packet - 10240

    Message successfully transferred with payload Bytes:0xf

    Message ID:0x100000

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Store Tx Events:0x1

    Message Marker:0xaa

    Message DataByte0:0xaa

    Message DataByte1:0xbd

    Message DataByte2:0x97

    Message DataByte3:0xca

    Message DataByte4:0x10

    Message DataByte5:0xd5

    Message DataByte6:0x2c

    Message DataByte7:0x14

    Message DataByte8:0x6e

    Message DataByte9:0xcc

    Message DataByte10:0x69

    Message DataByte11:0x21

    Message DataByte12:0xb8

    Message DataByte13:0x94

    Message DataByte14:0xf6
    Receiving data on port0

    Message successfully received with payload Bytes:0xf

    Received last message with following details:
    Message ID:0x110008

    Message Remote Transmission Request:0x0

    Message Extended Frame ID(0:11Bit ID/1:29bit ID):0x0

    Message Error State Indicator(0:Error Active/1:Error Passive):0x0

    Message TimeStamp:0x0

    Message Data Length Code:0xf

    Message BRS:0x1

    Message CAN FD format:0x1

    Message Filter Index:0x0

    Message Accept Non-matching Frame:0x0

    Message DataByte0:0xaa

    Message DataByte1:0xbd

    Message DataByte2:0x97

    Message DataByte3:0xca

    Message DataByte4:0x10

    Message DataByte5:0xd5

    Message DataByte6:0x2c

    Message DataByte7:0x14

    Message DataByte8:0x6e

    Message DataByte9:0xcc

    Message DataByte10:0x69

    Message DataByte11:0x21

    Message DataByte12:0xb8

    Message DataByte13:0x94

    Message DataByte14:0xf6

    Received Packet - 10240


     MCAN diagnostic test completed.
    Finished running mcanStress_TEST, result passed!

|

UART Stress Test
^^^^^^^^^^^^^^^^^
This test verifies the UART serial port by sending 10MB of data to the serial console.
Data is received by the teraterm script on host PC and looped back to the board. Data is
recieved by the test running on the board and verified to confirm data match.

.. note::
   This test does not support SD boot execution and need to run from CCS over JTAG.
   Automation script is provided for teraterm application but the test should
   be functional with any utility that can receive the data over COM port and
   send it back on the same COM port.

Test Accessories
"""""""""""""""""
 - UART serial cable.
 - JTAG connection (on board or external as supported)
Different platforms may need different cable for accessing the serial port. Refer to HW manual
for more details.

Test Setup
"""""""""""
 - Connect the UART serial cable between the board UART port and host PC
 - Connect the JTAG port of the board to host PC
 - Setup serial console application on host PC with below configurations
 ::

    Baud rate    -    115200
    Data length  -    8 bit
    Parity       -    None
    Stop bits    -    1
    Flow control -    None

 - Four UART ports are verified on am65xx_evm platform and three UART ports are verified on am65xx_idk platform.
   Need to make above setup on all serial consoles connected to multiple ports on these platforms.

Test Execution
"""""""""""""""
 - Power ON the board and clear any data on the serial consoles
 - Run the TTL script from all the Teraterm consoles by selecting menu 'Control->Macro' and select the script file "am65xx_uart_stress_test_script.ttl"
 - Open CCS, launch the target config file for the platform under test and connect to the target
 - Load and run the UART diagnostic stress test binary (uartStress_diagExample_<BOARD>_<TARGET>.x<CORE>fg) on the <CORE> being used for the test.
 - Test script shall start displaying the messages on Teraterm consoles.
 - Test shall take few hours to complete and displays final result on the console.

Test Log
"""""""""""
Sample UART stress test log is shown below

::

    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~

    ....
    ....
    ....

    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:

    UART Stress Test Passed
|

RS485 UART Stress Test
^^^^^^^^^^^^^^^^^^^^^^^
This test verifies the RS485 UART serial port by sending 10MB of data to the serial console.
Data is received by the teraterm script on host PC and looped back to the board. Data is
recieved by the test running on the board and verified to confirm data match.

.. note::
   This test does not support SD boot execution and need to run from CCS over JTAG.
   Automation script is provided for teraterm application but the test should
   be functional with any utility that can receive the data over COM port and
   send it back on the same COM port.

Test Accessories
"""""""""""""""""
 - UART serial cable.
   RS485 to RS232 USB cable is used on AM65x IDK platform to run the test.
 - JTAG connection (on board or external as supported)
Different platforms may need different cable for accessing the serial port. Refer to HW manual
for more details.

Test Setup
"""""""""""
 - Connect the UART serial cable between the board RS485 UART port and host PC
 - Connect the JTAG port of the board to host PC
 - Setup serial console application on host PC with below configurations
 ::

    Baud rate    -    115200
    Data length  -    8 bit
    Parity       -    None
    Stop bits    -    1
    Flow control -    None

Test Execution
"""""""""""""""
 - Power ON the board and clear any data on the serial console
 - Run the TTL script from the Teraterm console by selecting menu 'Control->Macro' and select the script file "am65xx_uart_stress_test_script.ttl"
 - Open CCS, launch the target config file for the platform under test and connect to the target
 - Load and run the UART diagnostic stress test binary (rs485_uartStress_diagExample_<BOARD>_<TARGET>.x<CORE>fg) on the <CORE> being used for the test.
 - Test script shall start displaying the messages on Teraterm console.
 - Test shall take few hours to complete and displays final result on the console.

Test Log
"""""""""""
Sample RS485 UART stress test log is shown below

::

    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~

    ....
    ....
    ....

    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
    0123456789:

    PRU-ICSS UART Stress Test Passed
|

Power On Self Test (POST)
^^^^^^^^^^^^^^^^^^^^^^^^^^
This test runs automatically when diagnostic tests are booted.
Verifies the basic memories on the board and displays the test results.
It also displays the board ID content programmed onto the Board ID EEPROM.
After the diag boot, POST waits for 5 secs during which entering character 'b'
in the serial console skips the POST execution.
After the POST is executed, default diagnostic menu shall be displayed.

Test Accessories
"""""""""""""""""
No additional accessories are required for running this test.

Test Setup
"""""""""""
No specific test setup is needed. Use the default HW setup recommended in HW user manual.

Test Execution
"""""""""""""""
Test runs automatically. No execution steps needed.

Test Log
"""""""""""
Sample log for LED stress test is shown below

::

	DIAGNOSTIC TEST FRAMEWORK
	Version - 01.00.00.01
	Build Date - Apr  6 2019, Time - 03:47:24


	Command options:
		help - displays this help menu again
		run - run a diagnostic application
		status - prints the test status


	Running Power On Self Tests...
	Press 'b' to Skip the Test
	Parsing bootEepromCompliance_TEST
	Running bootEepromCompliance_TEST

	*********************************************
	*              Boot EEPROM Test                  *
	*********************************************

	Running Boot EEPROM test

	Detecting the Boot EEPROM device...

	Boot EEPROM device detection successful

	Boot EEPROM boundary verification test...

	Verifying the Boot EEPROM first page...

	Verifying the Boot EEPROM last page...

	Boot EEPROM boundary verification test successful

	Boot EEPROM test Passed

	Finished running bootEepromCompliance_TEST, result passed!
	Parsing memCompliance_TEST
	Running memCompliance_TEST

	*********************************************
	*              DDR Memory Test              *
	*********************************************

	Testing writing and reading memory
	board_external_memory_test: Start address (0x80000000),            end address (0xffffffff)
	Address Bus Test Started
	Writing to test area...
		Writing Memory 0x80000000
		Writing Memory 0x80000004
		Writing Memory 0x80000008
		Writing Memory 0x80000010
		Writing Memory 0x80000020
		Writing Memory 0x80000040
		Writing Memory 0x80000080
		Writing Memory 0x80000100
		Writing Memory 0x80000200
		Writing Memory 0x80000400
		Writing Memory 0x80000800
		Writing Memory 0x80001000
		Writing Memory 0x80002000
		Writing Memory 0x80004000
		Writing Memory 0x80008000
		Writing Memory 0x80010000
		Writing Memory 0x80020000
		Writing Memory 0x80040000
		Writing Memory 0x80080000
		Writing Memory 0x80100000
		Writing Memory 0x80200000
		Writing Memory 0x80400000
		Writing Memory 0x80800000
		Writing Memory 0x81000000
		Writing Memory 0x82000000
		Writing Memory 0x84000000
		Writing Memory 0x88000000
		Writing Memory 0x90000000
		Writing Memory 0xa0000000
		Writing Memory 0xc0000000
	Write finished!
	Checking values...
		Reading Memory 0x80000000
		Reading Memory 0x80000004
		Reading Memory 0x80000008
		Reading Memory 0x80000010
		Reading Memory 0x80000020
		Reading Memory 0x80000040
		Reading Memory 0x80000080
		Reading Memory 0x80000100
		Reading Memory 0x80000200
		Reading Memory 0x80000400
		Reading Memory 0x80000800
		Reading Memory 0x80001000
		Reading Memory 0x80002000
		Reading Memory 0x80004000
		Reading Memory 0x80008000
		Reading Memory 0x80010000
		Reading Memory 0x80020000
		Reading Memory 0x80040000
		Reading Memory 0x80080000
		Reading Memory 0x80100000
		Reading Memory 0x80200000
		Reading Memory 0x80400000
		Reading Memory 0x80800000
		Reading Memory 0x81000000
		Reading Memory 0x82000000
		Reading Memory 0x84000000
		Reading Memory 0x88000000
		Reading Memory 0x90000000
		Reading Memory 0xa0000000
		Reading Memory 0xc0000000
	Board memory test passed!
	Memory test passed!

	Finished running memCompliance_TEST, result passed!
	Parsing emmcCompliance_TEST
	Running emmcCompliance_TEST

	*********************************************
	*                 eMMC Test                 *
	*********************************************

	PASS: Read/Write Success for this block-0x300000

	PASS: Read/Write Success for this pattern

	Finished running emmcCompliance_TEST, result passed!
	Parsing norflashCompliance_TEST
	Running norflashCompliance_TEST

	***************************************
	*            SPI FlASH Test           *
	***************************************
	Reading Flash Device ID...
	Device ID 0 - 0x20
	Device ID 1 - 0xba
	Device ID 2 - 0x18
	Flash Device ID Match!

	Flash Device ID Read Passed!

	Verifying Sector - 0
	Data Read matches with Data written
	SPI Flash Test Passed!

	SPI NOR Flash Test Passed

	Finished running norflashCompliance_TEST, result passed!
	Parsing ospiCompliance_TEST
	Running ospiCompliance_TEST

	*********************************************
	*            OSPI FLASH Test                *
	*********************************************

	OSPI NOR device ID: 0x5b1a, manufacturer ID: 0x2c

	 Verifying the OSPI Flash first page...
	OSPI NOR Flash first page verification Successful

	OSPI NOR Flash verification Successful

	OSPI Flash Test Passed!

	Finished running ospiCompliance_TEST, result passed!
	Parsing ledCompliance_TEST
	Running ledCompliance_TEST

	*********************************************
	*                 LED Test                  *
	*********************************************

	Testing LED
	Blinking LEDs...
	Received: y

	Test PASSED!

	LED Test Passed

	Finished running ledCompliance_TEST, result passed!
	Parsing bootSwitchCompliance_TEST
	Running bootSwitchCompliance_TEST

	*********************************************
	*             Boot Switch Test              *
	*********************************************
	Boot Switch SW3 Value - OFF ON ON OFF OFF OFF OFF OFF OFF OFF
	Boot Switch SW2 Value - OFF OFF ON OFF OFF OFF OFF OFF OFF
	Boot Switch SW4 Value - OFF OFF

	Test Passed

	Finished running bootSwitchCompliance_TEST, result passed!
	Parsing eepromCompliance_TEST
	Running eepromCompliance_TEST

	*********************************************
	*              EEPROM Test                  *
	*********************************************

	CP Board:
	Displaying Header Fields
	========================
		Header ID: 0xee3355aa

	Displaying Board Info Fields
	============================
		Board Name: AM6-COMPROCEVM
		Design Revision: E3
		PROC Number: 0062
		Variant: 03
	PCB Revision: E3
	Schematic and BOM Revision: E3
	Software Revision: 01
	Vendor ID: 01
	Build Week: 30
	Build Year: 18
	Board ID: 4P0081
	Serial Number: 0017
	Displaying DDR Fields
	=====================	DDR Control Word: 5850

	Displaying MAC Info Fields
	==========================
		MAC Control Word: 08
		MAC ADDR0: 70-ff-76-1d-4c-40
		MAC ADDR1: 70-ff-76-1d-4c-41
	Test Passed
	Finished running eepromCompliance_TEST, result passed!


	Power On Self Test Result
	All Tests Passed

|

Compliance Tests
^^^^^^^^^^^^^^^^^^^^^^^^^^
Diagnostic tests include support for CE compliance verication for some of the
platforms. Compliance tests can be executed by selecting the menu option '0'
from the diagnostic test menu. These tests are intended for use by board vendor.

