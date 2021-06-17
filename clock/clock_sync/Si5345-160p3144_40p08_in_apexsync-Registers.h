/*
 * Si5345 Rev D Configuration Register Export Header File
 *
 * This file represents a series of Silicon Labs Si5345 Rev D 
 * register writes that can be performed to load a single configuration 
 * on a device. It was created by a Silicon Labs ClockBuilder Pro
 * export tool.
 *
 * Part:		                                       Si5345 Rev D
 * Design ID:                                          apexsync
 * Includes Pre/Post Download Control Register Writes: Yes
 * Created By:                                         ClockBuilder Pro v2.45 [2020-07-16]
 * Timestamp:                                          2020-11-09 11:23:22 GMT-05:00
 *
 * A complete design report corresponding to this export is included at the end 
 * of this header file.
 *
 */

#ifndef SI5345_REVD_REG_CONFIG_HEADER
#define SI5345_REVD_REG_CONFIG_HEADER

#define SI5345_REVD_REG_CONFIG_NUM_REGS				526

typedef struct
{
	unsigned int address; /* 16-bit register address */
	unsigned char value; /* 8-bit register data */

} si5345_revd_register_t;

si5345_revd_register_t si5345_revd_registers[SI5345_REVD_REG_CONFIG_NUM_REGS] =
{

	/* Start configuration preamble */
	{ 0x0B24, 0xC0 },
	{ 0x0B25, 0x00 },
	{ 0x0540, 0x01 },
	/* End configuration preamble */

	/* Delay 300 msec */
	/*    Delay is worst case time for device to complete any calibration */
	/*    that is running due to device state change previous to this script */
	/*    being processed. */

	/* Start configuration registers */
	{ 0x0006, 0x00 },
	{ 0x0007, 0x00 },
	{ 0x0008, 0x00 },
	{ 0x000B, 0x68 },
	{ 0x0016, 0x02 },
	{ 0x0017, 0xDC },
	{ 0x0018, 0xE6 },
	{ 0x0019, 0xDD },
	{ 0x001A, 0xDF },
	{ 0x002B, 0x02 },
	{ 0x002C, 0x09 },
	{ 0x002D, 0x41 },
	{ 0x002E, 0x47 },
	{ 0x002F, 0x00 },
	{ 0x0030, 0x00 },
	{ 0x0031, 0x00 },
	{ 0x0032, 0x00 },
	{ 0x0033, 0x00 },
	{ 0x0034, 0x47 },
	{ 0x0035, 0x00 },
	{ 0x0036, 0x47 },
	{ 0x0037, 0x00 },
	{ 0x0038, 0x00 },
	{ 0x0039, 0x00 },
	{ 0x003A, 0x00 },
	{ 0x003B, 0x00 },
	{ 0x003C, 0x47 },
	{ 0x003D, 0x00 },
	{ 0x003F, 0x11 },
	{ 0x0040, 0x04 },
	{ 0x0041, 0x0C },
	{ 0x0042, 0x00 },
	{ 0x0043, 0x00 },
	{ 0x0044, 0x0C },
	{ 0x0045, 0x0C },
	{ 0x0046, 0x32 },
	{ 0x0047, 0x00 },
	{ 0x0048, 0x00 },
	{ 0x0049, 0x00 },
	{ 0x004A, 0x32 },
	{ 0x004B, 0x00 },
	{ 0x004C, 0x00 },
	{ 0x004D, 0x00 },
	{ 0x004E, 0x05 },
	{ 0x004F, 0x00 },
	{ 0x0050, 0x07 },
	{ 0x0051, 0x03 },
	{ 0x0052, 0x00 },
	{ 0x0053, 0x00 },
	{ 0x0054, 0x00 },
	{ 0x0055, 0x03 },
	{ 0x0056, 0x00 },
	{ 0x0057, 0x00 },
	{ 0x0058, 0x00 },
	{ 0x0059, 0x01 },
	{ 0x005A, 0xA6 },
	{ 0x005B, 0xC0 },
	{ 0x005C, 0xD5 },
	{ 0x005D, 0x00 },
	{ 0x005E, 0x00 },
	{ 0x005F, 0x00 },
	{ 0x0060, 0x00 },
	{ 0x0061, 0x00 },
	{ 0x0062, 0x00 },
	{ 0x0063, 0x00 },
	{ 0x0064, 0x00 },
	{ 0x0065, 0x00 },
	{ 0x0066, 0x00 },
	{ 0x0067, 0x00 },
	{ 0x0068, 0x00 },
	{ 0x0069, 0x00 },
	{ 0x0092, 0x02 },
	{ 0x0093, 0xA0 },
	{ 0x0095, 0x00 },
	{ 0x0096, 0x80 },
	{ 0x0098, 0x60 },
	{ 0x009A, 0x02 },
	{ 0x009B, 0x60 },
	{ 0x009D, 0x04 },
	{ 0x009E, 0x40 },
	{ 0x00A0, 0x20 },
	{ 0x00A2, 0x00 },
	{ 0x00A9, 0xC7 },
	{ 0x00AA, 0x31 },
	{ 0x00AB, 0x00 },
	{ 0x00AC, 0x00 },
	{ 0x00E5, 0x00 },
	{ 0x00EA, 0x05 },
	{ 0x00EB, 0x30 },
	{ 0x00EC, 0x00 },
	{ 0x00ED, 0x00 },
	{ 0x0102, 0x01 },
	{ 0x0108, 0x02 },
	{ 0x0109, 0x09 },
	{ 0x010A, 0x3E },
	{ 0x010B, 0x18 },
	{ 0x010D, 0x02 },
	{ 0x010E, 0x09 },
	{ 0x010F, 0x3E },
	{ 0x0110, 0x18 },
	{ 0x0112, 0x02 },
	{ 0x0113, 0x09 },
	{ 0x0114, 0x3E },
	{ 0x0115, 0x18 },
	{ 0x0117, 0x02 },
	{ 0x0118, 0x09 },
	{ 0x0119, 0x3E },
	{ 0x011A, 0x18 },
	{ 0x011C, 0x02 },
	{ 0x011D, 0x09 },
	{ 0x011E, 0x3E },
	{ 0x011F, 0x18 },
	{ 0x0121, 0x02 },
	{ 0x0122, 0x09 },
	{ 0x0123, 0x3E },
	{ 0x0124, 0x18 },
	{ 0x0126, 0x02 },
	{ 0x0127, 0x09 },
	{ 0x0128, 0x3E },
	{ 0x0129, 0x18 },
	{ 0x012B, 0x01 },
	{ 0x012C, 0x09 },
	{ 0x012D, 0x3B },
	{ 0x012E, 0x28 },
	{ 0x0130, 0x01 },
	{ 0x0131, 0x09 },
	{ 0x0132, 0x3B },
	{ 0x0133, 0x28 },
	{ 0x013A, 0x02 },
	{ 0x013B, 0x09 },
	{ 0x013C, 0x3E },
	{ 0x013D, 0x18 },
	{ 0x013F, 0x00 },
	{ 0x0140, 0x08 },
	{ 0x0141, 0x40 },
	{ 0x0142, 0xFF },
	{ 0x0206, 0x00 },
	{ 0x0208, 0x19 },
	{ 0x0209, 0x00 },
	{ 0x020A, 0x00 },
	{ 0x020B, 0x00 },
	{ 0x020C, 0x00 },
	{ 0x020D, 0x00 },
	{ 0x020E, 0x01 },
	{ 0x020F, 0x00 },
	{ 0x0210, 0x00 },
	{ 0x0211, 0x00 },
	{ 0x0212, 0x00 },
	{ 0x0213, 0x00 },
	{ 0x0214, 0x00 },
	{ 0x0215, 0x00 },
	{ 0x0216, 0x00 },
	{ 0x0217, 0x00 },
	{ 0x0218, 0x00 },
	{ 0x0219, 0x00 },
	{ 0x021A, 0x00 },
	{ 0x021B, 0x00 },
	{ 0x021C, 0x00 },
	{ 0x021D, 0x00 },
	{ 0x021E, 0x00 },
	{ 0x021F, 0x00 },
	{ 0x0220, 0x00 },
	{ 0x0221, 0x00 },
	{ 0x0222, 0x00 },
	{ 0x0223, 0x00 },
	{ 0x0224, 0x00 },
	{ 0x0225, 0x00 },
	{ 0x0226, 0x19 },
	{ 0x0227, 0x00 },
	{ 0x0228, 0x00 },
	{ 0x0229, 0x00 },
	{ 0x022A, 0x00 },
	{ 0x022B, 0x00 },
	{ 0x022C, 0x01 },
	{ 0x022D, 0x00 },
	{ 0x022E, 0x00 },
	{ 0x022F, 0x00 },
	{ 0x0231, 0x0B },
	{ 0x0232, 0x0B },
	{ 0x0233, 0x0B },
	{ 0x0234, 0x0B },
	{ 0x0235, 0x00 },
	{ 0x0236, 0x00 },
	{ 0x0237, 0x18 },
	{ 0x0238, 0x15 },
	{ 0x0239, 0x0D },
	{ 0x023A, 0x01 },
	{ 0x023B, 0x00 },
	{ 0x023C, 0x00 },
	{ 0x023D, 0x60 },
	{ 0x023E, 0xEA },
	{ 0x024A, 0x03 },
	{ 0x024B, 0x00 },
	{ 0x024C, 0x00 },
	{ 0x024D, 0x03 },
	{ 0x024E, 0x00 },
	{ 0x024F, 0x00 },
	{ 0x0250, 0x03 },
	{ 0x0251, 0x00 },
	{ 0x0252, 0x00 },
	{ 0x0253, 0x03 },
	{ 0x0254, 0x00 },
	{ 0x0255, 0x00 },
	{ 0x0256, 0x03 },
	{ 0x0257, 0x00 },
	{ 0x0258, 0x00 },
	{ 0x0259, 0x03 },
	{ 0x025A, 0x00 },
	{ 0x025B, 0x00 },
	{ 0x025C, 0x03 },
	{ 0x025D, 0x00 },
	{ 0x025E, 0x00 },
	{ 0x025F, 0x00 },
	{ 0x0260, 0x00 },
	{ 0x0261, 0x00 },
	{ 0x0262, 0x00 },
	{ 0x0263, 0x00 },
	{ 0x0264, 0x00 },
	{ 0x0268, 0x0F },
	{ 0x0269, 0x00 },
	{ 0x026A, 0x00 },
	{ 0x026B, 0x61 },
	{ 0x026C, 0x70 },
	{ 0x026D, 0x65 },
	{ 0x026E, 0x78 },
	{ 0x026F, 0x73 },
	{ 0x0270, 0x79 },
	{ 0x0271, 0x6E },
	{ 0x0272, 0x63 },
	{ 0x028A, 0x00 },
	{ 0x028B, 0x00 },
	{ 0x028C, 0x00 },
	{ 0x028D, 0x00 },
	{ 0x028E, 0x00 },
	{ 0x028F, 0x00 },
	{ 0x0290, 0x00 },
	{ 0x0291, 0x00 },
	{ 0x0294, 0xC0 },
	{ 0x0296, 0x02 },
	{ 0x0297, 0x02 },
	{ 0x0299, 0x02 },
	{ 0x029D, 0x19 },
	{ 0x029E, 0x01 },
	{ 0x029F, 0x00 },
	{ 0x02A9, 0x66 },
	{ 0x02AA, 0x02 },
	{ 0x02AB, 0x00 },
	{ 0x02B7, 0xFF },
	{ 0x0302, 0x00 },
	{ 0x0303, 0x00 },
	{ 0x0304, 0x00 },
	{ 0x0305, 0x80 },
	{ 0x0306, 0x05 },
	{ 0x0307, 0x00 },
	{ 0x0308, 0x00 },
	{ 0x0309, 0x00 },
	{ 0x030A, 0x00 },
	{ 0x030B, 0x80 },
	{ 0x030C, 0x00 },
	{ 0x030D, 0x00 },
	{ 0x030E, 0x00 },
	{ 0x030F, 0x00 },
	{ 0x0310, 0x00 },
	{ 0x0311, 0x00 },
	{ 0x0312, 0x00 },
	{ 0x0313, 0x00 },
	{ 0x0314, 0x00 },
	{ 0x0315, 0x00 },
	{ 0x0316, 0x00 },
	{ 0x0317, 0x00 },
	{ 0x0318, 0x00 },
	{ 0x0319, 0x00 },
	{ 0x031A, 0x00 },
	{ 0x031B, 0x00 },
	{ 0x031C, 0x00 },
	{ 0x031D, 0x00 },
	{ 0x031E, 0x00 },
	{ 0x031F, 0x00 },
	{ 0x0320, 0x00 },
	{ 0x0321, 0x00 },
	{ 0x0322, 0x00 },
	{ 0x0323, 0x00 },
	{ 0x0324, 0x00 },
	{ 0x0325, 0x00 },
	{ 0x0326, 0x00 },
	{ 0x0327, 0x00 },
	{ 0x0328, 0x00 },
	{ 0x0329, 0x00 },
	{ 0x032A, 0x00 },
	{ 0x032B, 0x00 },
	{ 0x032C, 0x00 },
	{ 0x032D, 0x00 },
	{ 0x032E, 0x00 },
	{ 0x032F, 0x00 },
	{ 0x0330, 0x00 },
	{ 0x0331, 0x00 },
	{ 0x0332, 0x00 },
	{ 0x0333, 0x00 },
	{ 0x0334, 0x00 },
	{ 0x0335, 0x00 },
	{ 0x0336, 0x00 },
	{ 0x0337, 0x00 },
	{ 0x0338, 0x00 },
	{ 0x0339, 0x1F },
	{ 0x033B, 0x00 },
	{ 0x033C, 0x00 },
	{ 0x033D, 0x00 },
	{ 0x033E, 0x00 },
	{ 0x033F, 0x00 },
	{ 0x0340, 0x00 },
	{ 0x0341, 0x00 },
	{ 0x0342, 0x00 },
	{ 0x0343, 0x00 },
	{ 0x0344, 0x00 },
	{ 0x0345, 0x00 },
	{ 0x0346, 0x00 },
	{ 0x0347, 0x00 },
	{ 0x0348, 0x00 },
	{ 0x0349, 0x00 },
	{ 0x034A, 0x00 },
	{ 0x034B, 0x00 },
	{ 0x034C, 0x00 },
	{ 0x034D, 0x00 },
	{ 0x034E, 0x00 },
	{ 0x034F, 0x00 },
	{ 0x0350, 0x00 },
	{ 0x0351, 0x00 },
	{ 0x0352, 0x00 },
	{ 0x0353, 0x00 },
	{ 0x0354, 0x00 },
	{ 0x0355, 0x00 },
	{ 0x0356, 0x00 },
	{ 0x0357, 0x00 },
	{ 0x0358, 0x00 },
	{ 0x0359, 0x00 },
	{ 0x035A, 0x00 },
	{ 0x035B, 0x00 },
	{ 0x035C, 0x00 },
	{ 0x035D, 0x00 },
	{ 0x035E, 0x00 },
	{ 0x035F, 0x00 },
	{ 0x0360, 0x00 },
	{ 0x0361, 0x00 },
	{ 0x0362, 0x00 },
	{ 0x0487, 0x01 },
	{ 0x0508, 0x10 },
	{ 0x0509, 0x1F },
	{ 0x050A, 0x0D },
	{ 0x050B, 0x0C },
	{ 0x050C, 0x3F },
	{ 0x050D, 0x3F },
	{ 0x050E, 0x14 },
	{ 0x050F, 0x29 },
	{ 0x0510, 0x09 },
	{ 0x0511, 0x08 },
	{ 0x0512, 0x3F },
	{ 0x0513, 0x3F },
	{ 0x0515, 0x00 },
	{ 0x0516, 0x00 },
	{ 0x0517, 0x00 },
	{ 0x0518, 0x00 },
	{ 0x0519, 0x70 },
	{ 0x051A, 0x03 },
	{ 0x051B, 0x00 },
	{ 0x051C, 0x00 },
	{ 0x051D, 0x00 },
	{ 0x051E, 0x00 },
	{ 0x051F, 0x80 },
	{ 0x0521, 0x2B },
	{ 0x052A, 0x01 },
	{ 0x052B, 0x01 },
	{ 0x052C, 0x87 },
	{ 0x052D, 0x03 },
	{ 0x052E, 0x19 },
	{ 0x052F, 0x19 },
	{ 0x0531, 0x00 },
	{ 0x0532, 0x10 },
	{ 0x0533, 0x04 },
	{ 0x0534, 0x00 },
	{ 0x0535, 0x00 },
	{ 0x0536, 0x00 },
	{ 0x0537, 0x00 },
	{ 0x0538, 0x00 },
	{ 0x0539, 0x00 },
	{ 0x053A, 0x02 },
	{ 0x053B, 0x03 },
	{ 0x053C, 0x00 },
	{ 0x053D, 0x11 },
	{ 0x053E, 0x06 },
	{ 0x0589, 0x0F },
	{ 0x058A, 0x00 },
	{ 0x059B, 0xF8 },
	{ 0x059D, 0x10 },
	{ 0x059E, 0x21 },
	{ 0x059F, 0x0D },
	{ 0x05A0, 0x0C },
	{ 0x05A1, 0x3F },
	{ 0x05A2, 0x3F },
	{ 0x05A6, 0x03 },
	{ 0x0802, 0x35 },
	{ 0x0803, 0x05 },
	{ 0x0804, 0x00 },
	{ 0x0805, 0x00 },
	{ 0x0806, 0x00 },
	{ 0x0807, 0x00 },
	{ 0x0808, 0x00 },
	{ 0x0809, 0x00 },
	{ 0x080A, 0x00 },
	{ 0x080B, 0x00 },
	{ 0x080C, 0x00 },
	{ 0x080D, 0x00 },
	{ 0x080E, 0x00 },
	{ 0x080F, 0x00 },
	{ 0x0810, 0x00 },
	{ 0x0811, 0x00 },
	{ 0x0812, 0x00 },
	{ 0x0813, 0x00 },
	{ 0x0814, 0x00 },
	{ 0x0815, 0x00 },
	{ 0x0816, 0x00 },
	{ 0x0817, 0x00 },
	{ 0x0818, 0x00 },
	{ 0x0819, 0x00 },
	{ 0x081A, 0x00 },
	{ 0x081B, 0x00 },
	{ 0x081C, 0x00 },
	{ 0x081D, 0x00 },
	{ 0x081E, 0x00 },
	{ 0x081F, 0x00 },
	{ 0x0820, 0x00 },
	{ 0x0821, 0x00 },
	{ 0x0822, 0x00 },
	{ 0x0823, 0x00 },
	{ 0x0824, 0x00 },
	{ 0x0825, 0x00 },
	{ 0x0826, 0x00 },
	{ 0x0827, 0x00 },
	{ 0x0828, 0x00 },
	{ 0x0829, 0x00 },
	{ 0x082A, 0x00 },
	{ 0x082B, 0x00 },
	{ 0x082C, 0x00 },
	{ 0x082D, 0x00 },
	{ 0x082E, 0x00 },
	{ 0x082F, 0x00 },
	{ 0x0830, 0x00 },
	{ 0x0831, 0x00 },
	{ 0x0832, 0x00 },
	{ 0x0833, 0x00 },
	{ 0x0834, 0x00 },
	{ 0x0835, 0x00 },
	{ 0x0836, 0x00 },
	{ 0x0837, 0x00 },
	{ 0x0838, 0x00 },
	{ 0x0839, 0x00 },
	{ 0x083A, 0x00 },
	{ 0x083B, 0x00 },
	{ 0x083C, 0x00 },
	{ 0x083D, 0x00 },
	{ 0x083E, 0x00 },
	{ 0x083F, 0x00 },
	{ 0x0840, 0x00 },
	{ 0x0841, 0x00 },
	{ 0x0842, 0x00 },
	{ 0x0843, 0x00 },
	{ 0x0844, 0x00 },
	{ 0x0845, 0x00 },
	{ 0x0846, 0x00 },
	{ 0x0847, 0x00 },
	{ 0x0848, 0x00 },
	{ 0x0849, 0x00 },
	{ 0x084A, 0x00 },
	{ 0x084B, 0x00 },
	{ 0x084C, 0x00 },
	{ 0x084D, 0x00 },
	{ 0x084E, 0x00 },
	{ 0x084F, 0x00 },
	{ 0x0850, 0x00 },
	{ 0x0851, 0x00 },
	{ 0x0852, 0x00 },
	{ 0x0853, 0x00 },
	{ 0x0854, 0x00 },
	{ 0x0855, 0x00 },
	{ 0x0856, 0x00 },
	{ 0x0857, 0x00 },
	{ 0x0858, 0x00 },
	{ 0x0859, 0x00 },
	{ 0x085A, 0x00 },
	{ 0x085B, 0x00 },
	{ 0x085C, 0x00 },
	{ 0x085D, 0x00 },
	{ 0x085E, 0x00 },
	{ 0x085F, 0x00 },
	{ 0x0860, 0x00 },
	{ 0x0861, 0x00 },
	{ 0x090E, 0x02 },
	{ 0x0943, 0x00 },
	{ 0x0949, 0x09 },
	{ 0x094A, 0x09 },
	{ 0x094E, 0x49 },
	{ 0x094F, 0x02 },
	{ 0x095E, 0x00 },
	{ 0x0A02, 0x00 },
	{ 0x0A03, 0x01 },
	{ 0x0A04, 0x01 },
	{ 0x0A05, 0x01 },
	{ 0x0A14, 0x00 },
	{ 0x0A1A, 0x00 },
	{ 0x0A20, 0x00 },
	{ 0x0A26, 0x00 },
	{ 0x0A2C, 0x00 },
	{ 0x0B44, 0x2F },
	{ 0x0B46, 0x00 },
	{ 0x0B47, 0x06 },
	{ 0x0B48, 0x06 },
	{ 0x0B4A, 0x1E },
	{ 0x0B57, 0x0E },
	{ 0x0B58, 0x01 },
	/* End configuration registers */

	/* Start configuration postamble */
	{ 0x0514, 0x01 },
	{ 0x001C, 0x01 },
	{ 0x0540, 0x00 },
	{ 0x0B24, 0xC3 },
	{ 0x0B25, 0x02 },
	/* End configuration postamble */

};

/*
 * Design Report
 *
 * Overview
 * ========
 * Part:               Si5345ABCD Rev D
 * Project File:       F:\madorsky\cernbox\projects\silabs\apex\Si5345-160p3144_40p08_in_apexsync-Project.slabtimeproj
 * Design ID:          apexsync
 * Created By:         ClockBuilder Pro v2.45 [2020-07-16]
 * Timestamp:          2020-11-09 11:23:22 GMT-05:00
 * 
 * Design Rule Check
 * =================
 * Errors:
 * - No errors
 * 
 * Warnings:
 * - No warnings
 * 
 * Device Grade
 * ============
 * Maximum Output Frequency: 160.3144 MHz
 * Frequency Synthesis Mode: Integer
 * Frequency Plan Grade:     D
 * Minimum Base OPN:         Si5345D*
 * 
 * Base       Output Clock         Supported Frequency Synthesis Modes
 * OPN Grade  Frequency Range      (Typical Jitter)
 * ---------  -------------------  --------------------------------------------
 * Si5345A    100 Hz to 1.028 GHz  Integer (< 100 fs) and fractional (< 150 fs)
 * Si5345B    100 Hz to 350 MHz    "
 * Si5345C    100 Hz to 1.028 GHz  Integer only (< 100 fs)
 * Si5345D*   100 Hz to 350 MHz    "
 * 
 * * Based on your calculated frequency plan, a Si5345D grade device is
 * sufficient for your design. For more in-system configuration flexibility
 * (higher frequencies and/or to enable fractional synthesis), consider
 * selecting device grade Si5345A when specifying an ordering part number (OPN)
 * for your application. See the datasheet Ordering Guide for more information.
 * 
 * Design
 * ======
 * Host Interface:
 *    I/O Power Supply: VDD (Core)
 *    SPI Mode: 4-Wire
 *    I2C Address Range: 104d to 107d / 0x68 to 0x6B (selected via A0/A1 pins)
 * 
 * XA/XB:
 *    48 MHz (XTAL - Crystal)
 * 
 * Inputs:
 *     IN0: 40.0786 MHz
 *          Standard
 *     IN1: Unused
 *     IN2: Unused
 *     IN3: ZDM - 40.0786 MHz
 *          Standard
 * 
 * Outputs:
 *    OUT0: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT1: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT2: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT3: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT4: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT5: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT6: 160.3144 MHz
 *          Enabled, LVDS 1.8 V
 *    OUT7: Unused
 *    OUT8: Unused
 *    OUT9: ZDM - 40.0786 MHz
 *          Enabled, LVDS 1.8 V
 * 
 * Frequency Plan
 * ==============
 * Priority: maximize the number of low jitter outputs
 * 
 * Fvco = 14.1076672 GHz
 * Fpfd = 1.603144 MHz
 * Fms0 = 1.2825152 GHz
 * 
 * P dividers:
 *    P0  = 25
 *    P1  = Unused
 *    P2  = Unused
 *    P3  = 25
 *    Pxaxb = 1
 * 
 * MXAXB = 293.9097333333333333... [ 293 + 6823/7500 ]
 * M = 1760
 * N dividers:
 *    N0 (Zero Delay):
 *       Value: 11
 *       OUT0: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT1: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT2: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT3: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT4: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT5: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT6: 160.3144 MHz [ 160 + 393/1250 MHz ]
 *       OUT9: 40.0786 MHz [ 40 + 393/5000 MHz ]
 *    N1:
 *       Unused
 *    N2:
 *       Unused
 *    N3:
 *       Unused
 *    N4:
 *       Unused
 * 
 * R dividers:
 *    R0 = 8
 *    R1 = 8
 *    R2 = 8
 *    R3 = 8
 *    R4 = 8
 *    R5 = 8
 *    R6 = 8
 *    R7 = Unused
 *    R8 = Unused
 *    R9 = 32
 * 
 * Nominal Bandwidth:
 *   Desired: 100.000 Hz
 *   Actual:  78.009 Hz
 *   Coefficients:
 *      BW0:  16
 *      BW1:  31
 *      BW2:  13
 *      BW3:  12
 *      BW4:  63
 *      BW5:  63
 * Fastlock Bandwidth:
 *   Desired: 1.000 kHz
 *   Actual:  1.251 kHz
 *   Coefficients:
 *      BW0:  20
 *      BW1:  41
 *      BW2:  9
 *      BW3:  8
 *      BW4:  63
 *      BW5:  63
 * Holdover Bandwidth:
 *    N/A (Ramped Exit from Holdover)
 * 
 * Dividers listed above show effective values. These values are translated to register settings by ClockBuilder Pro. For the actual register values, see below. Refer to the Family Reference Manual for information on registers related to frequency plan.
 * 
 * Digitally Controlled Oscillator (DCO)
 * =====================================
 * Mode: FINC/FDEC
 * 
 * N0: DCO Disabled
 * 
 * N1: DCO Disabled
 * 
 * N2: DCO Disabled
 * 
 * N3: DCO Disabled
 * 
 * N4: DCO Disabled
 * 
 * Estimated Power & Junction Temperature
 * ======================================
 * Assumptions:
 * 
 * Revision: D
 * VDD:      1.8 V
 * Ta:       25 �C
 * Theta-JA: 18.3 �C/W
 * Airflow:  2 m/s
 * 
 * Total Power: 848 mW, On Chip Power: 800 mW, Tj: 40 �C
 * 
 *            Frequency  Format   Voltage   Current     Power
 *         ------------  ------  --------  --------  --------
 * VDD                              1.8 V  134.8 mA    243 mW
 * VDDA                             3.3 V  115.2 mA    380 mW
 * VDDO0   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO1   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO2   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO3   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO4   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO5   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO6   160.3144 MHz  LVDS       1.8 V   15.7 mA     28 mW
 * VDDO7         Unused                                      
 * VDDO8         Unused                                      
 * VDDO9    40.0786 MHz  LVDS       1.8 V   15.2 mA     27 mW
 *                                         --------  --------
 *                                  Total  375.3 mA    848 mW
 * 
 * Note:
 * 
 * -Tj is junction temperature. Tj must be less than 125 �C (on Si5345 Revision D) for device to comply with datasheet specifications. Tj = Ta + Theta_JA*On_Chip_Power.
 * -Overall power includes on-chip power dissipation and adds differential load power dissipation to estimate total power requirements.
 * -Above are estimates only: power and temperature should be measured on your PCB.
 * -Selection of appropriate Theta-JA is required for most accurate estimate. Ideally, select 'User Specified Theta-JA' and enter a Theta-JA value based on the thermal properties of your PCB.
 * 
 * Settings
 * ========
 * 
 * Location      Setting Name                Decimal Value      Hex Value        
 * ------------  --------------------------  -----------------  -----------------
 * 0x0006[23:0]  TOOL_VERSION                0                  0x000000         
 * 0x000B[6:0]   I2C_ADDR                    104                0x68             
 * 0x0016[1]     LOL_ON_HOLD                 1                  0x1              
 * 0x0017[0]     SYSINCAL_INTR_MSK           0                  0x0              
 * 0x0017[1]     LOSXAXB_INTR_MSK            0                  0x0              
 * 0x0017[5]     SMB_TMOUT_INTR_MSK          0                  0x0              
 * 0x0018[3:0]   LOS_INTR_MSK                6                  0x6              
 * 0x0018[7:4]   OOF_INTR_MSK                14                 0xE              
 * 0x0019[1]     LOL_INTR_MSK                0                  0x0              
 * 0x0019[5]     HOLD_INTR_MSK               0                  0x0              
 * 0x001A[5]     CAL_INTR_MSK                0                  0x0              
 * 0x002B[3]     SPI_3WIRE                   0                  0x0              
 * 0x002B[5]     AUTO_NDIV_UPDATE            0                  0x0              
 * 0x002C[3:0]   LOS_EN                      9                  0x9              
 * 0x002C[4]     LOSXAXB_DIS                 0                  0x0              
 * 0x002D[1:0]   LOS0_VAL_TIME               1                  0x1              
 * 0x002D[3:2]   LOS1_VAL_TIME               0                  0x0              
 * 0x002D[5:4]   LOS2_VAL_TIME               0                  0x0              
 * 0x002D[7:6]   LOS3_VAL_TIME               1                  0x1              
 * 0x002E[15:0]  LOS0_TRG_THR                71                 0x0047           
 * 0x0030[15:0]  LOS1_TRG_THR                0                  0x0000           
 * 0x0032[15:0]  LOS2_TRG_THR                0                  0x0000           
 * 0x0034[15:0]  LOS3_TRG_THR                71                 0x0047           
 * 0x0036[15:0]  LOS0_CLR_THR                71                 0x0047           
 * 0x0038[15:0]  LOS1_CLR_THR                0                  0x0000           
 * 0x003A[15:0]  LOS2_CLR_THR                0                  0x0000           
 * 0x003C[15:0]  LOS3_CLR_THR                71                 0x0047           
 * 0x003F[3:0]   OOF_EN                      1                  0x1              
 * 0x003F[7:4]   FAST_OOF_EN                 1                  0x1              
 * 0x0040[2:0]   OOF_REF_SEL                 4                  0x4              
 * 0x0041[4:0]   OOF0_DIV_SEL                12                 0x0C             
 * 0x0042[4:0]   OOF1_DIV_SEL                0                  0x00             
 * 0x0043[4:0]   OOF2_DIV_SEL                0                  0x00             
 * 0x0044[4:0]   OOF3_DIV_SEL                12                 0x0C             
 * 0x0045[4:0]   OOFXO_DIV_SEL               12                 0x0C             
 * 0x0046[7:0]   OOF0_SET_THR                50                 0x32             
 * 0x0047[7:0]   OOF1_SET_THR                0                  0x00             
 * 0x0048[7:0]   OOF2_SET_THR                0                  0x00             
 * 0x0049[7:0]   OOF3_SET_THR                0                  0x00             
 * 0x004A[7:0]   OOF0_CLR_THR                50                 0x32             
 * 0x004B[7:0]   OOF1_CLR_THR                0                  0x00             
 * 0x004C[7:0]   OOF2_CLR_THR                0                  0x00             
 * 0x004D[7:0]   OOF3_CLR_THR                0                  0x00             
 * 0x004E[2:0]   OOF0_DETWIN_SEL             5                  0x5              
 * 0x004E[6:4]   OOF1_DETWIN_SEL             0                  0x0              
 * 0x004F[2:0]   OOF2_DETWIN_SEL             0                  0x0              
 * 0x004F[6:4]   OOF3_DETWIN_SEL             0                  0x0              
 * 0x0050[3:0]   OOF_ON_LOS                  7                  0x7              
 * 0x0051[3:0]   FAST_OOF0_SET_THR           3                  0x3              
 * 0x0052[3:0]   FAST_OOF1_SET_THR           0                  0x0              
 * 0x0053[3:0]   FAST_OOF2_SET_THR           0                  0x0              
 * 0x0054[3:0]   FAST_OOF3_SET_THR           0                  0x0              
 * 0x0055[3:0]   FAST_OOF0_CLR_THR           3                  0x3              
 * 0x0056[3:0]   FAST_OOF1_CLR_THR           0                  0x0              
 * 0x0057[3:0]   FAST_OOF2_CLR_THR           0                  0x0              
 * 0x0058[3:0]   FAST_OOF3_CLR_THR           0                  0x0              
 * 0x0059[1:0]   FAST_OOF0_DETWIN_SEL        1                  0x1              
 * 0x0059[3:2]   FAST_OOF1_DETWIN_SEL        0                  0x0              
 * 0x0059[5:4]   FAST_OOF2_DETWIN_SEL        0                  0x0              
 * 0x0059[7:6]   FAST_OOF3_DETWIN_SEL        0                  0x0              
 * 0x005A[25:0]  OOF0_RATIO_REF              14008486           0x0D5C0A6        
 * 0x005E[25:0]  OOF1_RATIO_REF              0                  0x0000000        
 * 0x0062[25:0]  OOF2_RATIO_REF              0                  0x0000000        
 * 0x0066[25:0]  OOF3_RATIO_REF              0                  0x0000000        
 * 0x0092[1]     LOL_FST_EN                  1                  0x1              
 * 0x0093[7:4]   LOL_FST_DETWIN_SEL          10                 0xA              
 * 0x0095[3:2]   LOL_FST_VALWIN_SEL          0                  0x0              
 * 0x0096[7:4]   LOL_FST_SET_THR_SEL         8                  0x8              
 * 0x0098[7:4]   LOL_FST_CLR_THR_SEL         6                  0x6              
 * 0x009A[1]     LOL_SLOW_EN_PLL             1                  0x1              
 * 0x009B[7:4]   LOL_SLW_DETWIN_SEL          6                  0x6              
 * 0x009D[3:2]   LOL_SLW_VALWIN_SEL          1                  0x1              
 * 0x009E[7:4]   LOL_SLW_SET_THR             4                  0x4              
 * 0x00A0[7:4]   LOL_SLW_CLR_THR             2                  0x2              
 * 0x00A2[1]     LOL_TIMER_EN                0                  0x0              
 * 0x00A9[28:0]  LOL_CLR_DELAY_DIV256        12743              0x000031C7       
 * 0x00E5[0]     FASTLOCK_EXTEND_MASTER_DIS  0                  0x0              
 * 0x00E5[5]     FASTLOCK_EXTEND_EN          0                  0x0              
 * 0x00EA[28:0]  FASTLOCK_EXTEND             12293              0x00003005       
 * 0x0102[0]     OUTALL_DISABLE_LOW          1                  0x1              
 * 0x0108[0]     OUT0_PDN                    0                  0x0              
 * 0x0108[1]     OUT0_OE                     1                  0x1              
 * 0x0108[2]     OUT0_RDIV_FORCE2            0                  0x0              
 * 0x0109[2:0]   OUT0_FORMAT                 1                  0x1              
 * 0x0109[3]     OUT0_SYNC_EN                1                  0x1              
 * 0x0109[5:4]   OUT0_DIS_STATE              0                  0x0              
 * 0x0109[7:6]   OUT0_CMOS_DRV               0                  0x0              
 * 0x010A[3:0]   OUT0_CM                     14                 0xE              
 * 0x010A[6:4]   OUT0_AMPL                   3                  0x3              
 * 0x010B[2:0]   OUT0_MUX_SEL                0                  0x0              
 * 0x010B[5:4]   OUT0_VDD_SEL                1                  0x1              
 * 0x010B[3]     OUT0_VDD_SEL_EN             1                  0x1              
 * 0x010B[7:6]   OUT0_INV                    0                  0x0              
 * 0x010D[0]     OUT1_PDN                    0                  0x0              
 * 0x010D[1]     OUT1_OE                     1                  0x1              
 * 0x010D[2]     OUT1_RDIV_FORCE2            0                  0x0              
 * 0x010E[2:0]   OUT1_FORMAT                 1                  0x1              
 * 0x010E[3]     OUT1_SYNC_EN                1                  0x1              
 * 0x010E[5:4]   OUT1_DIS_STATE              0                  0x0              
 * 0x010E[7:6]   OUT1_CMOS_DRV               0                  0x0              
 * 0x010F[3:0]   OUT1_CM                     14                 0xE              
 * 0x010F[6:4]   OUT1_AMPL                   3                  0x3              
 * 0x0110[2:0]   OUT1_MUX_SEL                0                  0x0              
 * 0x0110[5:4]   OUT1_VDD_SEL                1                  0x1              
 * 0x0110[3]     OUT1_VDD_SEL_EN             1                  0x1              
 * 0x0110[7:6]   OUT1_INV                    0                  0x0              
 * 0x0112[0]     OUT2_PDN                    0                  0x0              
 * 0x0112[1]     OUT2_OE                     1                  0x1              
 * 0x0112[2]     OUT2_RDIV_FORCE2            0                  0x0              
 * 0x0113[2:0]   OUT2_FORMAT                 1                  0x1              
 * 0x0113[3]     OUT2_SYNC_EN                1                  0x1              
 * 0x0113[5:4]   OUT2_DIS_STATE              0                  0x0              
 * 0x0113[7:6]   OUT2_CMOS_DRV               0                  0x0              
 * 0x0114[3:0]   OUT2_CM                     14                 0xE              
 * 0x0114[6:4]   OUT2_AMPL                   3                  0x3              
 * 0x0115[2:0]   OUT2_MUX_SEL                0                  0x0              
 * 0x0115[5:4]   OUT2_VDD_SEL                1                  0x1              
 * 0x0115[3]     OUT2_VDD_SEL_EN             1                  0x1              
 * 0x0115[7:6]   OUT2_INV                    0                  0x0              
 * 0x0117[0]     OUT3_PDN                    0                  0x0              
 * 0x0117[1]     OUT3_OE                     1                  0x1              
 * 0x0117[2]     OUT3_RDIV_FORCE2            0                  0x0              
 * 0x0118[2:0]   OUT3_FORMAT                 1                  0x1              
 * 0x0118[3]     OUT3_SYNC_EN                1                  0x1              
 * 0x0118[5:4]   OUT3_DIS_STATE              0                  0x0              
 * 0x0118[7:6]   OUT3_CMOS_DRV               0                  0x0              
 * 0x0119[3:0]   OUT3_CM                     14                 0xE              
 * 0x0119[6:4]   OUT3_AMPL                   3                  0x3              
 * 0x011A[2:0]   OUT3_MUX_SEL                0                  0x0              
 * 0x011A[5:4]   OUT3_VDD_SEL                1                  0x1              
 * 0x011A[3]     OUT3_VDD_SEL_EN             1                  0x1              
 * 0x011A[7:6]   OUT3_INV                    0                  0x0              
 * 0x011C[0]     OUT4_PDN                    0                  0x0              
 * 0x011C[1]     OUT4_OE                     1                  0x1              
 * 0x011C[2]     OUT4_RDIV_FORCE2            0                  0x0              
 * 0x011D[2:0]   OUT4_FORMAT                 1                  0x1              
 * 0x011D[3]     OUT4_SYNC_EN                1                  0x1              
 * 0x011D[5:4]   OUT4_DIS_STATE              0                  0x0              
 * 0x011D[7:6]   OUT4_CMOS_DRV               0                  0x0              
 * 0x011E[3:0]   OUT4_CM                     14                 0xE              
 * 0x011E[6:4]   OUT4_AMPL                   3                  0x3              
 * 0x011F[2:0]   OUT4_MUX_SEL                0                  0x0              
 * 0x011F[5:4]   OUT4_VDD_SEL                1                  0x1              
 * 0x011F[3]     OUT4_VDD_SEL_EN             1                  0x1              
 * 0x011F[7:6]   OUT4_INV                    0                  0x0              
 * 0x0121[0]     OUT5_PDN                    0                  0x0              
 * 0x0121[1]     OUT5_OE                     1                  0x1              
 * 0x0121[2]     OUT5_RDIV_FORCE2            0                  0x0              
 * 0x0122[2:0]   OUT5_FORMAT                 1                  0x1              
 * 0x0122[3]     OUT5_SYNC_EN                1                  0x1              
 * 0x0122[5:4]   OUT5_DIS_STATE              0                  0x0              
 * 0x0122[7:6]   OUT5_CMOS_DRV               0                  0x0              
 * 0x0123[3:0]   OUT5_CM                     14                 0xE              
 * 0x0123[6:4]   OUT5_AMPL                   3                  0x3              
 * 0x0124[2:0]   OUT5_MUX_SEL                0                  0x0              
 * 0x0124[5:4]   OUT5_VDD_SEL                1                  0x1              
 * 0x0124[3]     OUT5_VDD_SEL_EN             1                  0x1              
 * 0x0124[7:6]   OUT5_INV                    0                  0x0              
 * 0x0126[0]     OUT6_PDN                    0                  0x0              
 * 0x0126[1]     OUT6_OE                     1                  0x1              
 * 0x0126[2]     OUT6_RDIV_FORCE2            0                  0x0              
 * 0x0127[2:0]   OUT6_FORMAT                 1                  0x1              
 * 0x0127[3]     OUT6_SYNC_EN                1                  0x1              
 * 0x0127[5:4]   OUT6_DIS_STATE              0                  0x0              
 * 0x0127[7:6]   OUT6_CMOS_DRV               0                  0x0              
 * 0x0128[3:0]   OUT6_CM                     14                 0xE              
 * 0x0128[6:4]   OUT6_AMPL                   3                  0x3              
 * 0x0129[2:0]   OUT6_MUX_SEL                0                  0x0              
 * 0x0129[5:4]   OUT6_VDD_SEL                1                  0x1              
 * 0x0129[3]     OUT6_VDD_SEL_EN             1                  0x1              
 * 0x0129[7:6]   OUT6_INV                    0                  0x0              
 * 0x012B[0]     OUT7_PDN                    1                  0x1              
 * 0x012B[1]     OUT7_OE                     0                  0x0              
 * 0x012B[2]     OUT7_RDIV_FORCE2            0                  0x0              
 * 0x012C[2:0]   OUT7_FORMAT                 1                  0x1              
 * 0x012C[3]     OUT7_SYNC_EN                1                  0x1              
 * 0x012C[5:4]   OUT7_DIS_STATE              0                  0x0              
 * 0x012C[7:6]   OUT7_CMOS_DRV               0                  0x0              
 * 0x012D[3:0]   OUT7_CM                     11                 0xB              
 * 0x012D[6:4]   OUT7_AMPL                   3                  0x3              
 * 0x012E[2:0]   OUT7_MUX_SEL                0                  0x0              
 * 0x012E[5:4]   OUT7_VDD_SEL                2                  0x2              
 * 0x012E[3]     OUT7_VDD_SEL_EN             1                  0x1              
 * 0x012E[7:6]   OUT7_INV                    0                  0x0              
 * 0x0130[0]     OUT8_PDN                    1                  0x1              
 * 0x0130[1]     OUT8_OE                     0                  0x0              
 * 0x0130[2]     OUT8_RDIV_FORCE2            0                  0x0              
 * 0x0131[2:0]   OUT8_FORMAT                 1                  0x1              
 * 0x0131[3]     OUT8_SYNC_EN                1                  0x1              
 * 0x0131[5:4]   OUT8_DIS_STATE              0                  0x0              
 * 0x0131[7:6]   OUT8_CMOS_DRV               0                  0x0              
 * 0x0132[3:0]   OUT8_CM                     11                 0xB              
 * 0x0132[6:4]   OUT8_AMPL                   3                  0x3              
 * 0x0133[2:0]   OUT8_MUX_SEL                0                  0x0              
 * 0x0133[5:4]   OUT8_VDD_SEL                2                  0x2              
 * 0x0133[3]     OUT8_VDD_SEL_EN             1                  0x1              
 * 0x0133[7:6]   OUT8_INV                    0                  0x0              
 * 0x013A[0]     OUT9_PDN                    0                  0x0              
 * 0x013A[1]     OUT9_OE                     1                  0x1              
 * 0x013A[2]     OUT9_RDIV_FORCE2            0                  0x0              
 * 0x013B[2:0]   OUT9_FORMAT                 1                  0x1              
 * 0x013B[3]     OUT9_SYNC_EN                1                  0x1              
 * 0x013B[5:4]   OUT9_DIS_STATE              0                  0x0              
 * 0x013B[7:6]   OUT9_CMOS_DRV               0                  0x0              
 * 0x013C[3:0]   OUT9_CM                     14                 0xE              
 * 0x013C[6:4]   OUT9_AMPL                   3                  0x3              
 * 0x013D[2:0]   OUT9_MUX_SEL                0                  0x0              
 * 0x013D[5:4]   OUT9_VDD_SEL                1                  0x1              
 * 0x013D[3]     OUT9_VDD_SEL_EN             1                  0x1              
 * 0x013D[7:6]   OUT9_INV                    0                  0x0              
 * 0x013F[11:0]  OUTX_ALWAYS_ON              2048               0x800            
 * 0x0141[1]     OUT_DIS_MSK                 0                  0x0              
 * 0x0141[5]     OUT_DIS_LOL_MSK             0                  0x0              
 * 0x0141[6]     OUT_DIS_LOSXAXB_MSK         1                  0x1              
 * 0x0141[7]     OUT_DIS_MSK_LOS_PFD         0                  0x0              
 * 0x0142[1]     OUT_DIS_MSK_LOL             1                  0x1              
 * 0x0142[5]     OUT_DIS_MSK_HOLD            1                  0x1              
 * 0x0206[1:0]   PXAXB                       0                  0x0              
 * 0x0208[47:0]  P0_NUM                      25                 0x000000000019   
 * 0x020E[31:0]  P0_DEN                      1                  0x00000001       
 * 0x0212[47:0]  P1_NUM                      0                  0x000000000000   
 * 0x0218[31:0]  P1_DEN                      0                  0x00000000       
 * 0x021C[47:0]  P2_NUM                      0                  0x000000000000   
 * 0x0222[31:0]  P2_DEN                      0                  0x00000000       
 * 0x0226[47:0]  P3_NUM                      25                 0x000000000019   
 * 0x022C[31:0]  P3_DEN                      1                  0x00000001       
 * 0x0231[3:0]   P0_FRACN_MODE               11                 0xB              
 * 0x0231[4]     P0_FRACN_EN                 0                  0x0              
 * 0x0232[3:0]   P1_FRACN_MODE               11                 0xB              
 * 0x0232[4]     P1_FRACN_EN                 0                  0x0              
 * 0x0233[3:0]   P2_FRACN_MODE               11                 0xB              
 * 0x0233[4]     P2_FRACN_EN                 0                  0x0              
 * 0x0234[3:0]   P3_FRACN_MODE               11                 0xB              
 * 0x0234[4]     P3_FRACN_EN                 0                  0x0              
 * 0x0235[43:0]  MXAXB_NUM                   1155700097024      0x10D15180000    
 * 0x023B[31:0]  MXAXB_DEN                   3932160000         0xEA600000       
 * 0x024A[23:0]  R0_REG                      3                  0x000003         
 * 0x024D[23:0]  R1_REG                      3                  0x000003         
 * 0x0250[23:0]  R2_REG                      3                  0x000003         
 * 0x0253[23:0]  R3_REG                      3                  0x000003         
 * 0x0256[23:0]  R4_REG                      3                  0x000003         
 * 0x0259[23:0]  R5_REG                      3                  0x000003         
 * 0x025C[23:0]  R6_REG                      3                  0x000003         
 * 0x025F[23:0]  R7_REG                      0                  0x000000         
 * 0x0262[23:0]  R8_REG                      0                  0x000000         
 * 0x0268[23:0]  R9_REG                      15                 0x00000F         
 * 0x026B[7:0]   DESIGN_ID0                  97                 0x61             
 * 0x026C[7:0]   DESIGN_ID1                  112                0x70             
 * 0x026D[7:0]   DESIGN_ID2                  101                0x65             
 * 0x026E[7:0]   DESIGN_ID3                  120                0x78             
 * 0x026F[7:0]   DESIGN_ID4                  115                0x73             
 * 0x0270[7:0]   DESIGN_ID5                  121                0x79             
 * 0x0271[7:0]   DESIGN_ID6                  110                0x6E             
 * 0x0272[7:0]   DESIGN_ID7                  99                 0x63             
 * 0x028A[4:0]   OOF0_TRG_THR_EXT            0                  0x00             
 * 0x028B[4:0]   OOF1_TRG_THR_EXT            0                  0x00             
 * 0x028C[4:0]   OOF2_TRG_THR_EXT            0                  0x00             
 * 0x028D[4:0]   OOF3_TRG_THR_EXT            0                  0x00             
 * 0x028E[4:0]   OOF0_CLR_THR_EXT            0                  0x00             
 * 0x028F[4:0]   OOF1_CLR_THR_EXT            0                  0x00             
 * 0x0290[4:0]   OOF2_CLR_THR_EXT            0                  0x00             
 * 0x0291[4:0]   OOF3_CLR_THR_EXT            0                  0x00             
 * 0x0294[7:4]   FASTLOCK_EXTEND_SCL         12                 0xC              
 * 0x0296[1]     LOL_SLW_VALWIN_SELX         1                  0x1              
 * 0x0297[1]     FASTLOCK_DLY_ONSW_EN        1                  0x1              
 * 0x0299[1]     FASTLOCK_DLY_ONLOL_EN       1                  0x1              
 * 0x029D[19:0]  FASTLOCK_DLY_ONLOL          281                0x00119          
 * 0x02A9[19:0]  FASTLOCK_DLY_ONSW           614                0x00266          
 * 0x02B7[3:2]   LOL_NOSIG_TIME              3                  0x3              
 * 0x0302[43:0]  N0_NUM                      23622320128        0x00580000000    
 * 0x0308[31:0]  N0_DEN                      2147483648         0x80000000       
 * 0x030C[0]     N0_UPDATE                   0                  0x0              
 * 0x030D[43:0]  N1_NUM                      0                  0x00000000000    
 * 0x0313[31:0]  N1_DEN                      0                  0x00000000       
 * 0x0317[0]     N1_UPDATE                   0                  0x0              
 * 0x0318[43:0]  N2_NUM                      0                  0x00000000000    
 * 0x031E[31:0]  N2_DEN                      0                  0x00000000       
 * 0x0322[0]     N2_UPDATE                   0                  0x0              
 * 0x0323[43:0]  N3_NUM                      0                  0x00000000000    
 * 0x0329[31:0]  N3_DEN                      0                  0x00000000       
 * 0x032D[0]     N3_UPDATE                   0                  0x0              
 * 0x032E[43:0]  N4_NUM                      0                  0x00000000000    
 * 0x0334[31:0]  N4_DEN                      0                  0x00000000       
 * 0x0338[0]     N4_UPDATE                   0                  0x0              
 * 0x0338[1]     N_UPDATE                    0                  0x0              
 * 0x0339[4:0]   N_FSTEP_MSK                 31                 0x1F             
 * 0x033B[43:0]  N0_FSTEPW                   0                  0x00000000000    
 * 0x0341[43:0]  N1_FSTEPW                   0                  0x00000000000    
 * 0x0347[43:0]  N2_FSTEPW                   0                  0x00000000000    
 * 0x034D[43:0]  N3_FSTEPW                   0                  0x00000000000    
 * 0x0353[43:0]  N4_FSTEPW                   0                  0x00000000000    
 * 0x0359[15:0]  N0_DELAY                    0                  0x0000           
 * 0x035B[15:0]  N1_DELAY                    0                  0x0000           
 * 0x035D[15:0]  N2_DELAY                    0                  0x0000           
 * 0x035F[15:0]  N3_DELAY                    0                  0x0000           
 * 0x0361[15:0]  N4_DELAY                    0                  0x0000           
 * 0x0487[0]     ZDM_EN                      1                  0x1              
 * 0x0487[2:1]   ZDM_IN_SEL                  0                  0x0              
 * 0x0487[4]     ZDM_AUTOSW_EN               0                  0x0              
 * 0x0508[5:0]   BW0_PLL                     16                 0x10             
 * 0x0509[5:0]   BW1_PLL                     31                 0x1F             
 * 0x050A[5:0]   BW2_PLL                     13                 0x0D             
 * 0x050B[5:0]   BW3_PLL                     12                 0x0C             
 * 0x050C[5:0]   BW4_PLL                     63                 0x3F             
 * 0x050D[5:0]   BW5_PLL                     63                 0x3F             
 * 0x050E[5:0]   FASTLOCK_BW0_PLL            20                 0x14             
 * 0x050F[5:0]   FASTLOCK_BW1_PLL            41                 0x29             
 * 0x0510[5:0]   FASTLOCK_BW2_PLL            9                  0x09             
 * 0x0511[5:0]   FASTLOCK_BW3_PLL            8                  0x08             
 * 0x0512[5:0]   FASTLOCK_BW4_PLL            63                 0x3F             
 * 0x0513[5:0]   FASTLOCK_BW5_PLL            63                 0x3F             
 * 0x0515[55:0]  M_NUM                       3779571220480      0x00037000000000 
 * 0x051C[31:0]  M_DEN                       2147483648         0x80000000       
 * 0x0521[3:0]   M_FRAC_MODE                 11                 0xB              
 * 0x0521[4]     M_FRAC_EN                   0                  0x0              
 * 0x0521[5]     PLL_OUT_RATE_SEL            1                  0x1              
 * 0x052A[0]     IN_SEL_REGCTRL              1                  0x1              
 * 0x052A[3:1]   IN_SEL                      0                  0x0              
 * 0x052B[0]     FASTLOCK_AUTO_EN            1                  0x1              
 * 0x052B[1]     FASTLOCK_MAN                0                  0x0              
 * 0x052C[0]     HOLD_EN                     1                  0x1              
 * 0x052C[3]     HOLD_RAMP_BYP               0                  0x0              
 * 0x052C[4]     HOLDEXIT_BW_SEL1            0                  0x0              
 * 0x052C[7:5]   RAMP_STEP_INTERVAL          4                  0x4              
 * 0x052D[1]     HOLD_RAMPBYP_NOHIST         1                  0x1              
 * 0x052E[4:0]   HOLD_HIST_LEN               25                 0x19             
 * 0x052F[4:0]   HOLD_HIST_DELAY             25                 0x19             
 * 0x0531[4:0]   HOLD_REF_COUNT_FRC          0                  0x00             
 * 0x0532[23:0]  HOLD_15M_CYC_COUNT          1040               0x000410         
 * 0x0535[0]     FORCE_HOLD                  0                  0x0              
 * 0x0536[1:0]   CLK_SWITCH_MODE             0                  0x0              
 * 0x0536[2]     HSW_EN                      0                  0x0              
 * 0x0537[3:0]   IN_LOS_MSK                  0                  0x0              
 * 0x0537[7:4]   IN_OOF_MSK                  0                  0x0              
 * 0x0538[2:0]   IN0_PRIORITY                0                  0x0              
 * 0x0538[6:4]   IN1_PRIORITY                0                  0x0              
 * 0x0539[2:0]   IN2_PRIORITY                0                  0x0              
 * 0x0539[6:4]   IN3_PRIORITY                0                  0x0              
 * 0x053A[1:0]   HSW_MODE                    2                  0x2              
 * 0x053A[3:2]   HSW_PHMEAS_CTRL             0                  0x0              
 * 0x053B[9:0]   HSW_PHMEAS_THR              3                  0x003            
 * 0x053D[4:0]   HSW_COARSE_PM_LEN           17                 0x11             
 * 0x053E[4:0]   HSW_COARSE_PM_DLY           6                  0x06             
 * 0x0589[12:0]  CAP_SHORT_DELAY             15                 0x000F           
 * 0x059B[1]     INIT_LP_CLOSE_HO            0                  0x0              
 * 0x059B[4]     HOLD_PRESERVE_HIST          1                  0x1              
 * 0x059B[5]     HOLD_FRZ_WITH_INTONLY       1                  0x1              
 * 0x059B[6]     HOLDEXIT_BW_SEL0            1                  0x1              
 * 0x059B[7]     HOLDEXIT_STD_BO             1                  0x1              
 * 0x059D[5:0]   HOLDEXIT_BW0                16                 0x10             
 * 0x059E[5:0]   HOLDEXIT_BW1                33                 0x21             
 * 0x059F[5:0]   HOLDEXIT_BW2                13                 0x0D             
 * 0x05A0[5:0]   HOLDEXIT_BW3                12                 0x0C             
 * 0x05A1[5:0]   HOLDEXIT_BW4                63                 0x3F             
 * 0x05A2[5:0]   HOLDEXIT_BW5                63                 0x3F             
 * 0x05A6[2:0]   RAMP_STEP_SIZE              3                  0x3              
 * 0x05A6[3]     RAMP_SWITCH_EN              0                  0x0              
 * 0x0802[15:0]  FIXREGSA0                   1333               0x0535           
 * 0x0804[7:0]   FIXREGSD0                   0                  0x00             
 * 0x0805[15:0]  FIXREGSA1                   0                  0x0000           
 * 0x0807[7:0]   FIXREGSD1                   0                  0x00             
 * 0x0808[15:0]  FIXREGSA2                   0                  0x0000           
 * 0x080A[7:0]   FIXREGSD2                   0                  0x00             
 * 0x080B[15:0]  FIXREGSA3                   0                  0x0000           
 * 0x080D[7:0]   FIXREGSD3                   0                  0x00             
 * 0x080E[15:0]  FIXREGSA4                   0                  0x0000           
 * 0x0810[7:0]   FIXREGSD4                   0                  0x00             
 * 0x0811[15:0]  FIXREGSA5                   0                  0x0000           
 * 0x0813[7:0]   FIXREGSD5                   0                  0x00             
 * 0x0814[15:0]  FIXREGSA6                   0                  0x0000           
 * 0x0816[7:0]   FIXREGSD6                   0                  0x00             
 * 0x0817[15:0]  FIXREGSA7                   0                  0x0000           
 * 0x0819[7:0]   FIXREGSD7                   0                  0x00             
 * 0x081A[15:0]  FIXREGSA8                   0                  0x0000           
 * 0x081C[7:0]   FIXREGSD8                   0                  0x00             
 * 0x081D[15:0]  FIXREGSA9                   0                  0x0000           
 * 0x081F[7:0]   FIXREGSD9                   0                  0x00             
 * 0x0820[15:0]  FIXREGSA10                  0                  0x0000           
 * 0x0822[7:0]   FIXREGSD10                  0                  0x00             
 * 0x0823[15:0]  FIXREGSA11                  0                  0x0000           
 * 0x0825[7:0]   FIXREGSD11                  0                  0x00             
 * 0x0826[15:0]  FIXREGSA12                  0                  0x0000           
 * 0x0828[7:0]   FIXREGSD12                  0                  0x00             
 * 0x0829[15:0]  FIXREGSA13                  0                  0x0000           
 * 0x082B[7:0]   FIXREGSD13                  0                  0x00             
 * 0x082C[15:0]  FIXREGSA14                  0                  0x0000           
 * 0x082E[7:0]   FIXREGSD14                  0                  0x00             
 * 0x082F[15:0]  FIXREGSA15                  0                  0x0000           
 * 0x0831[7:0]   FIXREGSD15                  0                  0x00             
 * 0x0832[15:0]  FIXREGSA16                  0                  0x0000           
 * 0x0834[7:0]   FIXREGSD16                  0                  0x00             
 * 0x0835[15:0]  FIXREGSA17                  0                  0x0000           
 * 0x0837[7:0]   FIXREGSD17                  0                  0x00             
 * 0x0838[15:0]  FIXREGSA18                  0                  0x0000           
 * 0x083A[7:0]   FIXREGSD18                  0                  0x00             
 * 0x083B[15:0]  FIXREGSA19                  0                  0x0000           
 * 0x083D[7:0]   FIXREGSD19                  0                  0x00             
 * 0x083E[15:0]  FIXREGSA20                  0                  0x0000           
 * 0x0840[7:0]   FIXREGSD20                  0                  0x00             
 * 0x0841[15:0]  FIXREGSA21                  0                  0x0000           
 * 0x0843[7:0]   FIXREGSD21                  0                  0x00             
 * 0x0844[15:0]  FIXREGSA22                  0                  0x0000           
 * 0x0846[7:0]   FIXREGSD22                  0                  0x00             
 * 0x0847[15:0]  FIXREGSA23                  0                  0x0000           
 * 0x0849[7:0]   FIXREGSD23                  0                  0x00             
 * 0x084A[15:0]  FIXREGSA24                  0                  0x0000           
 * 0x084C[7:0]   FIXREGSD24                  0                  0x00             
 * 0x084D[15:0]  FIXREGSA25                  0                  0x0000           
 * 0x084F[7:0]   FIXREGSD25                  0                  0x00             
 * 0x0850[15:0]  FIXREGSA26                  0                  0x0000           
 * 0x0852[7:0]   FIXREGSD26                  0                  0x00             
 * 0x0853[15:0]  FIXREGSA27                  0                  0x0000           
 * 0x0855[7:0]   FIXREGSD27                  0                  0x00             
 * 0x0856[15:0]  FIXREGSA28                  0                  0x0000           
 * 0x0858[7:0]   FIXREGSD28                  0                  0x00             
 * 0x0859[15:0]  FIXREGSA29                  0                  0x0000           
 * 0x085B[7:0]   FIXREGSD29                  0                  0x00             
 * 0x085C[15:0]  FIXREGSA30                  0                  0x0000           
 * 0x085E[7:0]   FIXREGSD30                  0                  0x00             
 * 0x085F[15:0]  FIXREGSA31                  0                  0x0000           
 * 0x0861[7:0]   FIXREGSD31                  0                  0x00             
 * 0x090E[0]     XAXB_EXTCLK_EN              0                  0x0              
 * 0x0943[0]     IO_VDD_SEL                  0                  0x0              
 * 0x0949[3:0]   IN_EN                       9                  0x9              
 * 0x0949[7:4]   IN_PULSED_CMOS_EN           0                  0x0              
 * 0x094A[3:0]   INX_TO_PFD_EN               9                  0x9              
 * 0x094E[11:0]  REFCLK_HYS_SEL              585                0x249            
 * 0x095E[0]     MXAXB_INTEGER               0                  0x0              
 * 0x0A02[4:0]   N_ADD_0P5                   0                  0x00             
 * 0x0A03[4:0]   N_CLK_TO_OUTX_EN            1                  0x01             
 * 0x0A04[4:0]   N_PIBYP                     1                  0x01             
 * 0x0A05[4:0]   N_PDNB                      1                  0x01             
 * 0x0A14[3]     N0_HIGH_FREQ                0                  0x0              
 * 0x0A1A[3]     N1_HIGH_FREQ                0                  0x0              
 * 0x0A20[3]     N2_HIGH_FREQ                0                  0x0              
 * 0x0A26[3]     N3_HIGH_FREQ                0                  0x0              
 * 0x0A2C[3]     N4_HIGH_FREQ                0                  0x0              
 * 0x0B44[3:0]   PDIV_FRACN_CLK_DIS          15                 0xF              
 * 0x0B44[5]     FRACN_CLK_DIS_PLL           1                  0x1              
 * 0x0B46[3:0]   LOS_CLK_DIS                 0                  0x0              
 * 0x0B47[4:0]   OOF_CLK_DIS                 6                  0x06             
 * 0x0B48[4:0]   OOF_DIV_CLK_DIS             6                  0x06             
 * 0x0B4A[4:0]   N_CLK_DIS                   30                 0x1E             
 * 0x0B57[11:0]  VCO_RESET_CALCODE           270                0x10E
 * 
 *
 */

#endif
