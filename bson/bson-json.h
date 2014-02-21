/*
 * Copyright 2014 MongoDB Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#if !defined (BSON_INSIDE) && !defined (BSON_COMPILATION)
# error "Only <bson.h> can be included directly."
#endif


#ifndef BSON_JSON_H
#define BSON_JSON_H


#include "bson.h"


BSON_BEGIN_DECLS


typedef struct _bson_json_reader_t bson_json_reader_t;


typedef enum
{
   BSON_JSON_ERROR_READ = 1,
} bson_json_error_domain_t;


typedef enum
{
   BSON_JSON_ERROR_READ_CORRUPT_JS = 1,
   BSON_JSON_ERROR_READ_INVALID_PARAM,
   BSON_JSON_ERROR_READ_CB_FAILURE,
} bson_json_error_code_t;


typedef ssize_t (*bson_json_reader_cb) (void    *handle,
                                        uint8_t *buf,
                                        size_t   count);
typedef void    (*bson_json_destroy_cb)(void    *handle);


bson_json_reader_t  *bson_json_reader_new        (void                 *data,
                                                  bson_json_reader_cb   cb,
                                                  bson_json_destroy_cb  dcb,
                                                  bool                  allow_multiple,
                                                  size_t                buf_size);
void                bson_json_reader_destroy     (bson_json_reader_t   *reader);
int                 bson_json_reader_read        (bson_json_reader_t   *reader,
                                                  bson_t               *bson,
                                                  bson_error_t         *error);
bson_json_reader_t *bson_json_data_reader_new    (bool                  allow_multiple,
                                                  size_t                size);
void                bson_json_data_reader_ingest (bson_json_reader_t   *reader,
                                                  const uint8_t        *data,
                                                  size_t                len);


BSON_END_DECLS


#endif /* BSON_JSON_H */
