/*
 * Copyright 2021 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_ContextUtils_DEFINED
#define skgpu_ContextUtils_DEFINED

#include "experimental/graphite/include/Context.h"
#include "include/core/SkBlendMode.h"
#include "include/core/SkSpan.h"
#include "include/core/SkTileMode.h"

enum class CodeSnippetID : uint8_t;
class SkPaintParamsKeyBuilder;
class SkPipelineData;
class SkShaderCodeDictionary;
class SkUniform;
class SkUniquePaintParamsID;

namespace skgpu {

class PaintParams;

std::tuple<SkUniquePaintParamsID, std::unique_ptr<SkPipelineData>> ExtractPaintData(
        Recorder*,
        SkPaintParamsKeyBuilder* builder,
        const PaintParams&);

} // namespace skgpu

#endif // skgpu_ContextUtils_DEFINED
