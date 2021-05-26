# libkotfmod [unfinished]

## What is this?

FMOD **Studio API** bindings for GameMaker Studio 2.3.

## What do you mean by Studio API?

Studio API is the one that's used together with the FMOD Studio suite.

There are Core API bindings but they are kind of unfinished.

## For which platforms?

Windows (32 and 64 bit), Linux (64 bit only), and Android (all four CPU architectures).

## Is it free?

Well, *libkotfmod* itself is free, but FMOD has it's own licensing options.

[See here](https://www.fmod.com/licensing "FMOD Licensing").

## How do I build it myself if I want to?

Just drop `fmodstudioapi20109android`, `fmodstudioapi20109win` or `fmodstudioapi20109linux`

developer packages into the repo directory, then use the appropriate script/project file.

- Windows (or UWP): libkotfmod.sln
- Linux: build.linux.sh (you might need to run `dos2unix` on that file if it doesn't execute)
- Android: build.android.bat (must have Android NDK installed and %ANDROID_NDK_ROOT% set correctly)

The Windows project will also automatically execute [GmxGen](https://github.com/YAL-GameMaker-Tools/GmxGen "tool's website")

to update the function definitions in the GameMaker project.

## How do I use it?

[See documentation](https://github.com/nkrapivin/libkotfmod/wiki "The Wiki").

## Credits

- Firelight Technologies Pty Ltd for [FMOD](https://www.fmod.com "their website").
- [YellowAfterlife](https://yal.cc "his website") for [GmxGen](https://github.com/YAL-GameMaker-Tools/GmxGen "tool's website").
- @DatZach for some JNI tips. :eyes:
