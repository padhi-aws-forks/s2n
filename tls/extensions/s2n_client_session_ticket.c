/*
 * Copyright 2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <sys/param.h>
#include <stdint.h>

#include "tls/extensions/s2n_client_session_ticket.h"
#include "tls/s2n_tls.h"
#include "tls/s2n_tls_parameters.h"

#include "utils/s2n_safety.h"

int s2n_extensions_client_session_ticket_send(struct s2n_connection *conn, struct s2n_stuffer *out)
{
    uint16_t client_ticket_len = conn->client_ticket.size;
    
    GUARD(s2n_stuffer_write_uint16(out, TLS_EXTENSION_SESSION_TICKET));
    GUARD(s2n_stuffer_write_uint16(out, client_ticket_len));
    GUARD(s2n_stuffer_write(out, &conn->client_ticket));

    return 0;
}