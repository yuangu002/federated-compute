/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef FCP_CLIENT_ENGINE_COMMON_H_
#define FCP_CLIENT_ENGINE_COMMON_H_

#include <string>
#include <vector>

#include "absl/container/flat_hash_set.h"
#include "absl/status/status.h"
#include "fcp/client/engine/engine.pb.h"
#include "fcp/protos/plan.pb.h"
#include "tensorflow/core/framework/tensor.h"

namespace fcp {
namespace client {
namespace engine {

// The result of a call to `SimplePlanEngine::RunPlan` or
// `TfLitePlanEngine::RunPlan`.
struct PlanResult {
  explicit PlanResult(engine::PhaseOutcome outcome) : outcome(outcome) {}

  // The outcome of the plan execution.
  engine::PhaseOutcome outcome;
  // Only set if `outcome` is `COMPLETE`, otherwise this is empty.
  std::vector<tensorflow::Tensor> output_tensors;
  // Only set if `outcome` is `COMPLETE`, otherwise this is empty.
  std::vector<std::string> output_names;

  PlanResult(PlanResult&&) = default;
  PlanResult& operator=(PlanResult&&) = default;

  // Disallow copy and assign.
  PlanResult(const PlanResult&) = delete;
  PlanResult& operator=(const PlanResult&) = delete;
};

// Validates that the input tensors match what's inside the TensorflowSpec.
absl::Status ValidateTensorflowSpec(
    const google::internal::federated::plan::TensorflowSpec& tensorflow_spec,
    const absl::flat_hash_set<std::string>& expected_input_tensor_names_set,
    const std::vector<std::string>& output_names);
}  // namespace engine
}  // namespace client
}  // namespace fcp

#endif  // FCP_CLIENT_ENGINE_COMMON_H_