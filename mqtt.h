//
// mqtt.c - MQTT client API for grblHAL
//
// v0.2 / 2025-03-04 / Io Engineering / Terje
//

/*

Copyright (c) 2023-2025, Terje Io

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its contributors may
be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#pragma once

typedef void (*on_mqtt_client_connected_ptr)(bool connected);
typedef bool (*on_mqtt_message_received_ptr)(const char *topic, const void *payload, size_t payload_length);

typedef struct {
    on_mqtt_client_connected_ptr on_client_connected;
    on_mqtt_message_received_ptr on_message_received;
} mqtt_events_t;

extern mqtt_events_t mqtt_events;

bool mqtt_connect (network_info_t *network, mqtt_settings_t *settings);
bool mqtt_publish_message (const char *topic, const void *payload, size_t payload_length, uint8_t qos, bool retain);
bool mqtt_subscribe_topic (const char *topic, uint8_t qos, on_mqtt_message_received_ptr on_message_received);
bool mqtt_unsubscribe_topic (const char *topic, on_mqtt_message_received_ptr on_message_received);

