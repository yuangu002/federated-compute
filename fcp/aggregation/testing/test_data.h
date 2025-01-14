/*
 * Copyright 2022 Google LLC
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

#ifndef FCP_AGGREGATION_TESTING_TEST_DATA_H_
#define FCP_AGGREGATION_TESTING_TEST_DATA_H_

#include <initializer_list>
#include <memory>

#include "fcp/aggregation/core/vector_data.h"

namespace fcp::aggregation {

// Creates test tensor data based on a vector<T>.
template <typename T>
std::unique_ptr<VectorData<T>> CreateTestData(std::initializer_list<T> values) {
  return std::make_unique<VectorData<T>>(values);
}

}  // namespace fcp::aggregation

#endif  // FCP_AGGREGATION_TESTING_TEST_DATA_H_
