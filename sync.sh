#!/bin/sh

set -e

base_dir="$(cd "$(dirname "$0")" || exit 1; pwd)"
keymap_name="f8"
qmk_home="$HOME/qmk_firmware"

printf 'using qmk firmware in %s.\n' "$qmk_home" 

if [ -d "${qmk_home:?}" ]; then
    cd "${base_dir:?}" || exit 1
    cp -ar "4x12" "${qmk_home:?}/keyboards/handwired/"
    cp -ar "lily58" "${qmk_home:?}/keyboards/lily58/keymaps/${keymap_name:?}"
fi

printf 'done.\n'
