// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "arrow/matlab/array/proxy/array.h"

namespace arrow::matlab::array::proxy {

    Array::Array(const libmexclass::proxy::FunctionArguments& constructor_arguments) {

        // Register Proxy methods.
        REGISTER_METHOD(Array, ToString);
        REGISTER_METHOD(Array, ToMatlab);
        REGISTER_METHOD(Array, Length);
    }

    void Array::ToString(libmexclass::proxy::method::Context& context) {
        ::matlab::data::ArrayFactory factory;

        // TODO: handle non-ascii characters
        auto str_mda = factory.createScalar(array->ToString());
        context.outputs[0] = str_mda;
    }

    void Array::Length(libmexclass::proxy::method::Context& context) {
        ::matlab::data::ArrayFactory factory;
        auto length_mda = factory.createScalar(array->length());
        context.outputs[0] = length_mda;
    }
}
