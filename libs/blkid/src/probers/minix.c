/*
 * Copyright (C) 1999 by Andries Brouwer
 * Copyright (C) 1999, 2000, 2003 by Theodore Ts'o
 * Copyright (C) 2001 by Andreas Dilger
 * Copyright (C) 2004 Kay Sievers <kay.sievers@vrfy.org>
 * Copyright (C) 2008 Karel Zak <kzak@redhat.com>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "blkidP.h"

static int probe_minix(blkid_probe pr, const struct blkid_idmag *mag)
{
	/* for more details see magic strings below */
	switch(mag->magic[1]) {
	case '\023':
		blkid_probe_set_version(pr, "1");
		break;
	case '\044':
		blkid_probe_set_version(pr, "2");
		break;
	case '\115':
		blkid_probe_set_version(pr, "3");
		break;
	}
	return 0;
}


const struct blkid_idinfo minix_idinfo =
{
	.name		= "minix",
	.usage		= BLKID_USAGE_FILESYSTEM,
	.probefunc	= probe_minix,
	.magics		=
	{
		/* version 1 */
		{ .magic = "\177\023", .len = 2, .kboff = 1, .sboff = 0x10 },
		{ .magic = "\217\023", .len = 2, .kboff = 1, .sboff = 0x10 },

		/* version 2 */
		{ .magic = "\150\044", .len = 2, .kboff = 1, .sboff = 0x10 },
		{ .magic = "\170\044", .len = 2, .kboff = 1, .sboff = 0x10 },

		/* version 3 */
		{ .magic = "\132\115", .len = 2, .kboff = 1, .sboff = 0x18 },
		{ NULL }
	}
};

