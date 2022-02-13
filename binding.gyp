{
    "targets": [
        {
            "target_name": "deduba_os",
            "conditions": [
                [
                    'OS=="mac"',
                    {
                        "cflags+": ["-fvisibility=hidden"],
                        "xcode_settings": {
                            "GCC_SYMBOLS_PRIVATE_EXTERN": "YES",  # -fvisibility=hidden
                        },
                    },
                ],
            ],
            "include_dirs+": ["<!(node -p \"require('node-addon-api').include_dir\")"],
            "sources": ["deduba_os.cc"],
            "defines+": [
                "NAPI_DISABLE_CPP_EXCEPTIONS",
                "NODE_ADDON_API_ENABLE_MAYBE",
                "NODE_ADDON_API_DISABLE_DEPRECATED",
            ],
        }
    ]
}
