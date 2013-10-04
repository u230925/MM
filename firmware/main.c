/*
 * Author: Minux
 * Author: Xiangfu Liu <xiangfu@openmobilefree.net>
 * Bitcoin:	1CanaaniJzgps8EV6Sfmpb7T8RutpaeyFn
 *
 * This is free and unencumbered software released into the public domain.
 * For details see the UNLICENSE file at the root of the source tree.
 */

#include "stdbool.h"
#include "stdio.h"
#include "sdk.h"
#include "minilibc.h"

#include "system_config.h"
#include "io.h"
#include "serial.h"

#define likely(x)   (x)
#define unlikely(x) (x)

static void set_led(uint32_t led)
{
	volatile uint32_t *gpio_pio_data = (uint32_t *)GPIO_BASE;

	*gpio_pio_data = led;
}

static void delay(volatile uint32_t i)
{
	while (i--)
		;
}

const char *stratum = "{"
"\"params\": [\"1380763043 1101\", "
"\"5506102164edbcbd90a8b0d617618e0c724dad2a58b640620000000000000000\", "
"\"01000000010000000000000000000000000000000000000000000000000000000000000000ffffffff510301fd030d00456c696769757300524cc5a3fabe6d6d6eac9f79d09de75047cd6dad7e13bd3067d6f6406b443d4347c3527c549f89e10400000000000000002f7373312f00\", "
"\"ffffffff2f0893b912000000001976a9145ad4df36c38579badb7113919d5664ff24d8c30b88ac16302d0c000000001976a91415b533475bb31e9c992e054b7e210194b0b382e688ac95af210c000000001976a9142f790c69fbf82ca1cc1cd08c7bcd9785bf285af088aca39fb60b000000001976a914512fe364168d51895cf5d12825eb8478a021bc8c88ac935d5a0a000000001976a9146ba1807121fdcb390db917b4ce84b0dc8e70883e88ac6609bd08000000001976a91485c9ce4366b559c0a1a65940586d33ce1ccdc31f88ac55fc9907000000001976a914f8159668b1e026c4390e39567c6805b3669643cf88ac24e22b06000000001976a914b259972b33d57f702b329a4d5a6b67a0759ed3ac88ac49bfb004000000001976a91480935fe3274069f6b0fd305e5c4d837991dbb12788ac46c31604000000001976a914e444fca561fcd4ecc12d75d145a8fdd0602199fe88acd7930003000000001976a9148c35417ab7ad8bab823bb4e8abf3b3b2c48a85b688acac48ef02000000001976a9145fbf44cc19f3cf91b94c17caff18b2f286813f7888ace3a96902000000001976a9148eafb1970e427d4d6ebb213b737b7dcdc96791e988ac5299ca01000000001976a914fe14cc64463da4f490198e4059ba7ad251d22e5b88ac2f37a601000000001976a9146f9f75a14ac7aa1c2b5f7c9aa9921ebc0bb84fea88acd4598d01000000001976a9146841e967d950fdd25fdd2f7a8ca87eb8f1d85ca788ace4308b01000000001976a914582b9290dfe30bb9b449de96043cb9db743e7a2288ac56c38a01000000001976a91497a8b3304d167fcef320136c67b44ae9ea97aefb88ac3b948801000000001976a9144f1cff8f980b15be09510a276c19c6aeb379381a88ac5cb27301000000001976a914ae8b96ace8e4e9325d304b962529e98a86334c9288acb2bc5d01000000001976a914af16a73fabf6df7446ff7bc9eabb11ad7d59382788ac3ab82101000000001976a914c8459142759347c481684590dabf11d9f91e143f88acddee1201000000001976a9140ab7c66bdfeada57e4619e896e17f754dabedcef88ac22741201000000001976a914d1a625cb20c6c513bb65b9b1e5699ba6e9b6c5b288ac0e5f1201000000001976a9140de2ca64176650db7763f4f3d6e362564b44fed588ac687c0d01000000001976a914fefa4447eb8f681b8473d43e7d845e55f3a35afa88acc53d0d01000000001976a914472427e6c7bbf78ad5ace308f94315b4d27c313e88ac8a920c01000000001976a91425e424d1ef97788b58aff2d069f28503aef163e488ac04730c01000000001976a914ef6d92b3a6dab1689c90a4d3bc9687e4c42f6b9d88ac261e0a01000000001976a91425c94f424c6e3466d78162da9b1a72616eddeba488ac256a0701000000001976a9146a37e007a500d470ba6623570ac87980e39ce98a88ac678c0301000000001976a914c17e44923f07ddd95b030cee63e94bea7a28550288ac69050301000000001976a914be86e5669d71f8f87faf000165bb3ad0288ec7d388acaa2b0201000000001976a914454dda256c717d10e819851ee3874d1ffd33bfd688ac62a17d00000000001976a914efbc2767dc16218e89e11eff19f88a3e3b3f0a1b88ac342e4100000000001976a9143adb8dc33166fe5f9a86b8ed6e8f745f0cce39e988ac8a202f00000000001976a914e44a4389826eb1bfa040f3ce18b8fb2a763f9e5488aca6192300000000001976a9142c3e7a35ec9f75084971ba15390ffef10cef69be88ac1fb42000000000001976a9144543f47812977801c563c7f548ddc298f1c9d7ad88ac5dae1c00000000001976a9148e2b31c1668133263fdd2d57571712810ee3bfe388acd7281b00000000001976a9145e2a5618487fc541479fa5b4ae13cf9f2986d6ff88acf8a11800000000001976a91402b82aa28674e1e80df69e5418b6232d7c57e5e388accfcb1000000000001976a9142d9f14d72a85974f1726dca16366706576c68e0088ac1a291000000000001976a91404e575a332c660249c504703f3e81f486294f99c88acc0121000000000001976a9144ee3a81efbc3526426ca46b699fb6641d6c39cf088ac00000010000000001976a91480563a02639dbb5eaa5be230f172b036ade336c388ac51060603000000001976a9145399c3093d31e4b0af4be1215d59b857b861ad5d88ac00000000\", "
 "["
  "\"4e1e966afd6c076743f60d908e8607c166e79490662ac73004c0bd7650af16cf\", "
  "\"5d9f256aa0dc3b46c18933050cc82aae0c01b1ba1b882b2ff378102945ea0953\", "
  "\"61d1f8f8cb041c7c77b7379b0f1df2ebc0b26467318fac692fa1a75a00a22181\", "
  "\"0bc44973f3f3d06222a5fef231d75e93757b6d1d54d189e4bf955fd35ef79a29\", "
  "\"c4a2bcf92d698bc3a5593bad9c8ea8bc7ca69a084ebfc304154ea1c0476832ea\", "
  "\"c20efa30fdfd8011553342bbdc10195a07e09d6e3e18547086908076ac00604c\", "
  "\"f95e1c938c0c93b0ee57d813d6648c2d95fe7ab69677f043d8328afeefae4319\", "
  "\"5c7aa100fbe903aa3ab350edd3e80673dd0da1bb094d0aa05dd0b32730ecf7aa\", "
  "\"530d7cc9bb46d199c9a41dc9f89929669c9634ba4dc3152d28dd88acd3b2bcdb\", "
  "\"fb8093eaf26bb92f72c5e83d46db751142b5f27b7bc14413ec6d66b18c82e028\""
 "], "
"\"00000002\", "
"\"191cdc20\", "
"\"524cc5a3\", "
"false], "
"\"id\": null, "
"\"method\": \"mining.notify\""
"}";

bool hex2bin(unsigned char *p, const char *hexstr, size_t len)
{
	bool ret = false;

	while (*hexstr && len) {
		char hex_byte[4];
		unsigned int v;

		if (unlikely(!hexstr[1])) {
			//applog(LOG_ERR, "hex2bin str truncated");
			return ret;
		}

		memset(hex_byte, 0, 4);
		hex_byte[0] = hexstr[0];
		hex_byte[1] = hexstr[1];

		if (unlikely(sscanf(hex_byte, "%x", &v) != 1)) {
			//applog(LOG_INFO, "hex2bin sscanf '%s' failed", hex_byte);
			return ret;
		}

		*p = (unsigned char) v;

		p++;
		hexstr += 2;
		len--;
	}

	if (likely(len == 0 && *hexstr == 0))
		ret = true;
	return ret;
}

const char *result = "\n{\"params\": ["
	"\"usrid\"," // miner id
	"\"263884\", " // job id
	"\"62000000\"," // extra nonce
	"\"5214f239\"," // ntime
	"\"26a8c33c\"" // nonce
	"],"
	"\"id\": 297,"
	"\"method\": \"mining.submit\"}\n";

const uint32_t sha256_in[16] = {
	0x61626380, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000018};

const uint32_t sha256_in2[32] = {
	0x61626364, 0x62636465, 0x63646566, 0x64656667,
	0x65666768, 0x66676869, 0x6768696A, 0x68696A6B,
	0x696A6B6C, 0x6A6B6C6D, 0x6B6C6D6E, 0x6C6D6E6F,
	0x6D6E6F70, 0x6E6F7071, 0x80000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x000001C0};

static void sha256_transform(uint32_t *state, const uint32_t *input, int count)
{
	struct lm32_sha256 *sha256 = (struct lm32_sha256 *)SHA256_BASE;

	int i;

	writel(LM32_SHA256_CMD_INIT, &sha256->cmd);
	for (i = 0; i < count; i++) {
		writel(input[i], &sha256->in);
		if (!((i + 1) % 16))
			while (!(readl(&sha256->cmd) & LM32_SHA256_CMD_DONE))
				;
	}
	for (i = 0; i < 8; i++)
		state[i] = readl(&sha256->out);
}

int main(void) {
	uint8_t tmp;
	uint32_t j, state[8];

	uart_init();

	/* Test serial console */
	serial_puts(result);

	/* Test sha256 core: 1 block data*/
	sha256_transform(state, sha256_in, 16);
	for (j = 0; j < 8; j++) {
		serial_putc((state[j] & 0x000000ff) >> 0);
		serial_putc((state[j] & 0x0000ff00) >> 8);
		serial_putc((state[j] & 0x00ff0000) >> 16);
		serial_putc((state[j] & 0xff000000) >> 24);
	}
	serial_puts("UUUU");

	/* Test sha256 core: 2 block data*/
	sha256_transform(state, sha256_in2, 32);
	for (j = 0; j < 8; j++) {
		serial_putc((state[j] & 0x000000ff) >> 0);
		serial_putc((state[j] & 0x0000ff00) >> 8);
		serial_putc((state[j] & 0x00ff0000) >> 16);
		serial_putc((state[j] & 0xff000000) >> 24);
	}
	serial_puts("UUUU");

	/* Test GPIO */
	j = 1;
	while (1) {
		delay(4000000);

		j++;
		set_led(0x00345678 | (j << 24));

		tmp = serial_getc();
		serial_putc(tmp);
	}

	return 0;
}

/* vim: set ts=4 sw=4 fdm=marker : */
