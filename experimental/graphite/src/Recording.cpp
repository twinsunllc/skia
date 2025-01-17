/*
 * Copyright 2021 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "experimental/graphite/include/Recording.h"

#include "experimental/graphite/src/CommandBuffer.h"
#include "experimental/graphite/src/PipelineDataCache.h"

namespace skgpu {

Recording::Recording(sk_sp<CommandBuffer> commandBuffer,
                     std::unique_ptr<TextureDataCache> textureDataCache)
        : fCommandBuffer(std::move(commandBuffer))
        , fTextureDataCache(std::move(textureDataCache)) {
}

Recording::~Recording() {}

} // namespace skgpu
