// Copyright 2018 Espressif Systems (Shanghai) PTE LTD
// All rights reserved.

#ifndef _ALEXA_H_
#define _ALEXA_H_

#include "voice_assistant.h"
#include "auth_delegate.h"

/** The Alexa Configuration Structure
 */
typedef struct {
    va_playback_config_t va_playback;
    char *device_serial_num;
    char *product_id;
} alexa_config_t;

/** Initialize Alexa
 *
 * This call must be made after the Wi-Fi connection has been established with the configured Access Point.
 *
 * \param[in] cfg The Alexa Configuration
 *
 * \return
 *    - 0 on Success
 *    - an error code otherwise
 */
int alexa_init(alexa_config_t *cfg);

/** Initialise Alexa Bluetooth
 *
 * This enables Alexa's Bluetooth A2DP sink functionality.
 */
int alexa_bluetooth_init();

/** Enable Larger tones.
 *
 * This API will enable a tone which would be played if dialog is in progress and timer/alarm goes off.
 * Enabling this tone would increase size of binary by around 356 KB.
 */
void alexa_tone_enable_larger_tones();

/** Change Alexa Language.
 *
 * This API can be used to change the default locale i.e language and/or accent for Alexa. The supported locales can be found here: https://developer.amazon.com/docs/alexa-voice-service/settings.html
 */
void alexa_change_locale(const char *locale);

void alexa_auth_delegate_signin(auth_delegate_config_t *cfg);
void alexa_auth_delegate_signout();
void alexa_signin_handler(const char *client_id, const char *refresh_token);
void alexa_signout_handler();

#endif /*_ALEXA_H_ */
