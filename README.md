# Introduction
A replacement dds plugin for 3ds Max, that provides support for newer dwFlags used in textures for DX10+ games. 

# Background
When Bethesda released the Creation Kit for Fallout 4, the download included various other mod tools - a NIF format exporter for 3ds Max 2015 was among those tools. Unfortunately 3ds Max 2015 doesn't support all the dds formats
that Fallout 4 uses, so Bethesda suggested using what they did - TGA format. However, if one should have the desire to create models using existing textures, messing around with converting back and forth between image 
formats, can quickly become tedious. Enter this plugin - which helps alleviate some of that tediousness, as it *does* support all the Fallout 4 dds files. 

# Caveats
1. This requires replacing the existing 3ds Max dds plugin - it is suggested that you make a backup in case you need it again. 
2. It does not play nicely with the BSLightingFX material. However, you should be able to use BSBlinn without issue. 
3. Some rendering methods/materials will not play nicely with this plugin. Unfortunately Autodesk did not release the source for the vanilla dds plugin, so this was created from scratch. 

# Requirements
1. A 3ds Max SDK - the Solution is currently set up for the 2015 SDK, others should be able to be configured in the same way. 
2. ATI/AMD Compress 1.80 - Newer versions *may* work, but I cannot verify this. The particular library used was the static library VS2010\MT DLL Release\x64\ATI_Compress_MT_DLL.lib
3. Visual Studio 2010, or at least its C/C++ compiler (v100)
