/*
 * Copyright (c) 2021, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "nvcomp.h"
#include "SnappyKernels.h"
#include "nvcomp_common_deps/hlif_shared_types.h"

namespace nvcomp {

void snappyHlifBatchCompress(
    CommonHeader* common_header,
    const uint8_t* decomp_buffer, 
    const size_t decomp_buffer_size, 
    uint8_t* comp_buffer, 
    uint8_t* tmp_buffer,
    const size_t raw_chunk_size,
    size_t* ix_output,
    uint32_t* ix_chunk,
    const size_t num_chunks,
    const size_t max_comp_chunk_size,
    size_t* comp_chunk_offsets,
    size_t* comp_chunk_sizes,
    const uint32_t max_ctas,
    cudaStream_t stream,
    nvcompStatus_t* output_status);

void snappyHlifBatchDecompress(
    const uint8_t* comp_buffer, 
    uint8_t* decomp_buffer, 
    const size_t raw_chunk_size,
    uint32_t* ix_chunk,
    const size_t num_chunks,
    const size_t* comp_chunk_offsets,
    const size_t* comp_chunk_sizes,
    const uint32_t max_ctas,
    cudaStream_t stream,
    nvcompStatus_t* output_status);

size_t snappyHlifDecompMaxBlockOccupancy(const int device_id); 
size_t snappyHlifCompMaxBlockOccupancy(const int device_id);

} // namespace nvcomp
