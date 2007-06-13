/*
 * Copyright (C) 2007 Oracle.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

#ifndef __TRANSACTION__
#define __TRANSACTION__

struct btrfs_trans_handle {
	u64 transid;
	unsigned long blocks_reserved;
	unsigned long blocks_used;
};

static inline struct btrfs_trans_handle *
btrfs_start_transaction(struct btrfs_root *root, int num_blocks)
{
	struct btrfs_trans_handle *h = malloc(sizeof(*h));
	h->transid = root->root_key.offset;
	h->blocks_reserved = num_blocks;
	h->blocks_used = 0;
	return h;
}

static inline void btrfs_free_transaction(struct btrfs_root *root,
					  struct btrfs_trans_handle *handle)
{
	memset(handle, 0, sizeof(*handle));
	free(handle);
}

#endif