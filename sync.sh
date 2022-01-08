#!/bin/sh

set -e

base_dir="$(cd "$(dirname "$0")" || exit 1; pwd)"
qmk_home="$HOME/qmk_firmware"

printf 'using qmk firmware in %s.\n' "$qmk_home" 

sync_files()
{
    src="$1"
    dest="$2"
    printf 'synchronizing %s\n' "$1"
    if [ -d "$dest" ]; then
        rm -r "$dest"
    fi
    cp -arT "$src" "$dest"
}

if [ -d "${qmk_home:?}" ]; then
    cd "${base_dir:?}" || exit 1
    sync_files "userspace" "${qmk_home:?}/users/f8"
    sync_files "4x12" "${qmk_home:?}/keyboards/handwired/4x12"
    sync_files "lily58" "${qmk_home:?}/keyboards/lily58/keymaps/f8"
    sync_files "ploopy_mini" "${qmk_home:?}/keyboards/ploopyco/trackball_mini/keymaps/f8"
fi

printf 'done.\n'
