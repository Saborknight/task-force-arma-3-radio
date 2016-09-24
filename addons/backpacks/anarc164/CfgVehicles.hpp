class tf_anarc164: TFAR_Bag_Base {
    displayName = "AN/ARC-164";
    descriptionShort = "AN/ARC-164 airborne radio 40km";//#Stringtable
    picture = QPATHOF(anarc164\ui\anarc164_icon.paa);
    model = QPATHOF(models\TFR_BACKPACK);
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {QPATHTOF(models\data\camo\backpack_dpcu_co.paa)};
    scope = 2;
    scopeCurator = 2;
    maximumLoad = 20;
    mass = 160;
    tf_range = 40000;
    tf_encryptionCode = "tf_guer_radio_code";
    tf_dialog = "anarc164_radio_dialog";
    tf_subtype = "airborne";
    tf_dialogUpdate = "[""%1""] call TFAR_fnc_updateLRDialogToChannel;";
};
