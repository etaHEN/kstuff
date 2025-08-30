cd BearSSL
x86intrin_path="$(dirname "$(gcc -E -x c - <<< '#include <x86intrin.h>' | grep '/x86intrin\.h"' | head -1 | cut -d '"' -f 2-2)")"
for i in clean "lib -j$(nproc)"; do make CC='gcc -nostdlib -nostdinc -isystem /proc/'$$'/cwd/../../freebsd-headers -isystem '"'${x86intrin_path//"'"/"'"'"'"'"'"'"'"}'"' -O3 -march=znver2 -g -ffreestanding -ffunction-sections -fdata-sections -fvisibility=hidden -include /proc/'$$'/cwd/../overrides.h' $i; done
