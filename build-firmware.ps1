$SourceDir = "$PSScriptRoot"
$TargetDir = "/qmk_firmware"
docker run --rm --workdir "$TargetDir" -it -v "${SourceDir}:${TargetDir}" qmkfm/qmk_cli:latest /bin/sh -c "qmk setup && qmk json2c -o keymap.c keychron-q4-iso-keychron_q4_iso_layout_iso_62_mine.json && qmk compile keymap.c"
docker run --rm --workdir "$TargetDir" -it -v "${SourceDir}:${TargetDir}" qmkfm/qmk_cli:latest qmk compile -kb keychron/q4/iso -km custom
