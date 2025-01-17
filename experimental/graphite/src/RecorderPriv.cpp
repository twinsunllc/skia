/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "experimental/graphite/src/RecorderPriv.h"

#include "experimental/graphite/src/Device.h"
#include "experimental/graphite/src/Gpu.h"
#include "experimental/graphite/src/TaskGraph.h"

namespace skgpu {

#define ASSERT_SINGLE_OWNER SKGPU_ASSERT_SINGLE_OWNER(fRecorder->singleOwner())

ResourceProvider* RecorderPriv::resourceProvider() const {
    return fRecorder->fResourceProvider.get();
}

UniformDataCache* RecorderPriv::uniformDataCache() const {
    return fRecorder->fUniformDataCache.get();
}

TextureDataCache* RecorderPriv::textureDataCache() const {
    return fRecorder->fTextureDataCache.get();
}

const Caps* RecorderPriv::caps() const {
    return fRecorder->fGpu->caps();
}

DrawBufferManager* RecorderPriv::drawBufferManager() const {
    return fRecorder->fDrawBufferManager.get();
}

void RecorderPriv::add(sk_sp<Task> task) {
    ASSERT_SINGLE_OWNER
    fRecorder->fGraph->add(std::move(task));
}

void RecorderPriv::flushTrackedDevices() {
    ASSERT_SINGLE_OWNER
    for (Device* device : fRecorder->fTrackedDevices) {
        device->flushPendingWorkToRecorder();
    }
}

} // namespace skgpu
