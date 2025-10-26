add_executable(z_texture_export
    TextureExport.cpp
    StdAfx.h
)

target_link_libraries(z_texture_export PRIVATE
    core_config
    core_utility
)

if(WIN32 OR "${CMAKE_SYSTEM}" MATCHES "Windows")
    target_compile_definitions(z_texture_export PRIVATE 
        NOMINMAX
        WIN32_LEAN_AND_MEAN
        NOGDI
        NOUSER
    )
    set_target_properties(z_texture_export PROPERTIES OUTPUT_NAME TextureExportZH)
else()
    set_target_properties(z_texture_export PROPERTIES OUTPUT_NAME textureexportzh)
endif()
