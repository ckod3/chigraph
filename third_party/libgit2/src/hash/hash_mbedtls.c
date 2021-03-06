/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#include "common.h"
#include "hash.h"
#include "hash/hash_mbedtls.h"

void git_hash_ctx_cleanup(git_hash_ctx *ctx)
{
    assert(ctx);
    mbedtls_sha1_free(&ctx->c);
}

int git_hash_init(git_hash_ctx *ctx)
{
    assert(ctx);
    mbedtls_sha1_init(&ctx->c);
    mbedtls_sha1_starts(&ctx->c);
    return 0;
}

int git_hash_update(git_hash_ctx *ctx, const void *data, size_t len)
{
    assert(ctx);
    mbedtls_sha1_update(&ctx->c, data, len);
    return 0;
}

int git_hash_final(git_oid *out, git_hash_ctx *ctx)
{
    assert(ctx);
    mbedtls_sha1_finish(&ctx->c, out->id);
    return 0;
}
