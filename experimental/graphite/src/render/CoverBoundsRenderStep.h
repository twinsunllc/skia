/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_render_CoverBoundsRenderStep_DEFINED
#define skgpu_render_CoverBoundsRenderStep_DEFINED

#include "experimental/graphite/src/Renderer.h"

namespace skgpu {

class CoverBoundsRenderStep final : public RenderStep {
public:
    CoverBoundsRenderStep(bool inverseFill);

    ~CoverBoundsRenderStep() override;

    const char* vertexSkSL() const override;
    void writeVertices(DrawWriter*, const DrawGeometry&) const override;
    sk_sp<SkUniformData> writeUniforms(Layout, const DrawGeometry&) const override;

private:
    const bool fInverseFill;
};

}  // namespace skgpu

#endif // skgpu_render_CoverBoundsRenderStep_DEFINED
