# vcpkg triplet that builds every dependency as a universal (arm64 + x86_64)
# macOS dylib.
#
# A universal *app* is only possible if its dependencies are universal too,
# because CMakeLists.txt copies them straight into Contents/Frameworks and
# re-signs them. Homebrew bottles are single-arch, so the dependencies have to
# be built from source: that is what this triplet is for.
#
# Usage (from the repository root):
#   vcpkg install \
#     --triplet universal-osx \
#     --overlay-triplets platform/macos/triplets \
#     --x-install-root "$PWD/vcpkg-deps" \
#     sdl2 sdl2-image sdl2-mixer sdl2-ttf jsoncpp

set(VCPKG_TARGET_ARCHITECTURE arm64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE dynamic)

# Both slices in a single build; vcpkg passes this through as
# CMAKE_OSX_ARCHITECTURES so each port produces a fat binary.
set(VCPKG_OSX_ARCHITECTURES "arm64;x86_64")

# Apple Silicon support starts at macOS 11, which is also what the app itself
# defaults to in CMakeLists.txt. Keeping them equal avoids a fat binary whose
# slices have different minimums.
set(VCPKG_OSX_DEPLOYMENT_TARGET "11.0")
