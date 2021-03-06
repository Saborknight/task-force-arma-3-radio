#define ADD_PHONE_ACTIONS \
class TFAR_External_Intercom_Phone_Base { \
    distance = 4; \
    exceptions = []; \
    icon = QPATHTOF(ui\tfar_ace_interaction_external_intercom_phone.paa); \
    position = "[_target] call TFAR_external_intercom_fnc_getInteractionPoint"; \
    selection = ""; \
}; \
class TFAR_External_Intercom_Phone_Connect : TFAR_External_Intercom_Phone_Base { \
    displayName = CSTRING(PICKUP_PHONE); \
    condition = "([(typeOf _target), 'TFAR_hasIntercom', 0] call TFAR_fnc_getVehicleConfigProperty) > 0 && (_target getVariable ['TFAR_ExternalIntercomSpeakers', [objNull, []]] select 0) isEqualTo objNull"; \
    statement = "call TFAR_external_intercom_fnc_connect;"; \
}; \
class TFAR_External_Intercom_Phone_Disconnect : TFAR_External_Intercom_Phone_Base { \
    displayName = CSTRING(PUT_AWAY_PHONE); \
    condition = "([(typeOf _target), 'TFAR_hasIntercom', 0] call TFAR_fnc_getVehicleConfigProperty) > 0 && (_target getVariable ['TFAR_ExternalIntercomSpeakers', [objNull, []]] select 0) isEqualTo _player"; \
    statement = "call TFAR_external_intercom_fnc_disconnect;"; \
}; \
class TFAR_External_Intercom_Phone_Busy : TFAR_External_Intercom_Phone_Base { \
    displayName = CSTRING(PHONE_BUSY); \
    condition = "_targetPhoneSpeaker = _target getVariable ['TFAR_ExternalIntercomSpeakers', [objNull, []]] select 0; ([(typeOf _target), 'TFAR_hasIntercom', 0] call TFAR_fnc_getVehicleConfigProperty) > 0 && !isNull _targetPhoneSpeaker && !(_targetPhoneSpeaker isEqualTo _player)"; \
    statement = " "; \
    icon = QPATHTOF(ui\tfar_ace_interaction_external_intercom_phone_busy.paa); \
};

#define ADD_WIRELESS_ACTIONS \
class ACE_MainActions { \
    class TFAR_External_Intercom_Wireless_Base { \
        distance = 4; \
        exceptions = []; \
        icon = QPATHTOF(ui\tfar_ace_interaction_external_intercom_wireless.paa); \
    }; \
    class TFAR_External_Intercom_Wireless_Connect : TFAR_External_Intercom_Wireless_Base { \
        displayName = CSTRING(CONNECT_WIRELESS); \
        condition = "([(typeOf _target), 'TFAR_hasIntercom', 0] call TFAR_fnc_getVehicleConfigProperty) > 0 && ((_target getVariable ['TFAR_ExternalIntercomSpeakers', [objNull, []]] select 1) find _player) < 0 && isClass(configFile >> 'TFAR_External_Intercom_Wireless_Headgear' >> (headgear _player))"; \
        statement = "_this set [2, [true]]; call TFAR_external_intercom_fnc_connect;"; \
    }; \
    class TFAR_External_Intercom_Wireless_Disconnect : TFAR_External_Intercom_Wireless_Base { \
        displayName = CSTRING(DISCONNECT_WIRELESS); \
        condition = "([(typeOf _target), 'TFAR_hasIntercom', 0] call TFAR_fnc_getVehicleConfigProperty) > 0 && ((_target getVariable ['TFAR_ExternalIntercomSpeakers', [objNull, []]] select 1) find _player) > -1"; \
        statement = "call TFAR_external_intercom_fnc_disconnect;"; \
        icon = QPATHTOF(ui\tfar_ace_interaction_external_intercom_wireless_disconnect.paa); \
    }; \
};
