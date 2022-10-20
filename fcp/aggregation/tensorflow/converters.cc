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

#include "fcp/aggregation/tensorflow/converters.h"

#include <vector>

#include "fcp/base/monitoring.h"

namespace fcp::aggregation::tensorflow {

namespace tf = ::tensorflow;

StatusOr<DataType> ConvertDataType(tf::DataType dtype) {
  switch (dtype) {
    case tf::DT_FLOAT:
      return DT_FLOAT;
    case tf::DT_DOUBLE:
      return DT_DOUBLE;
    case tf::DT_INT32:
      return DT_INT32;
    case tf::DT_INT64:
      return DT_INT64;
    default:
      return FCP_STATUS(INVALID_ARGUMENT)
             << "Unsupported tf::DataType: " << dtype;
  }
}

TensorShape ConvertShape(const tf::TensorShape& shape) {
  FCP_CHECK(shape.IsFullyDefined());
  std::vector<size_t> dim_sizes;
  for (auto dim_size : shape.dim_sizes()) {
    FCP_CHECK(dim_size >= 0);
    dim_sizes.push_back(dim_size);
  }
  return TensorShape(dim_sizes.begin(), dim_sizes.end());
}

}  // namespace fcp::aggregation::tensorflow