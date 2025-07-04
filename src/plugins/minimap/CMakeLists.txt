add_qtc_plugin(MinimapPlugin
  LONG_DESCRIPTION_MD README.md
  PLUGIN_DEPENDS
    Core
    TextEditor
  SOURCES
    minimap.cpp minimap.h
    minimap_global.h
    minimapconstants.h
    minimaptr.h
    minimapsettings.cpp minimapsettings.h
    minimapstyle.cpp minimapstyle.h
    README.md
)
