import bpy

bl_info = {
    "name": "AnimationController",
    "author": "Joseph Hansen",
    "version": (1, 0),
    "blender" : (3, 00, 0),
    "location": "",
    "warning": "",
    "wiki_url": "",
    "tracker_url": "",
    "category": "3D View"
}

frame_up = 10

class OBJECT_OT_SetOnion(bpy.types.Operator):
    """Tooltip"""
    bl_idname = "animationcontroller.setonion"
    bl_label = "Turn on Onion Skin for object"
    
    def execute(self, context):
        bpy.ops.anim_extras.set_onion()
        bpy.ops.anim_extras.update_onion()
        if bpy.data.scenes["Scene"].anmx_data.toggle == False:
            bpy.data.scenes["Scene"].anmx_data.toggle = True
        
        return {'FINISHED'}

class OBJECT_OT_FrameUp(bpy.types.Operator):
    """Tooltip"""
    bl_idname = "animationcontroller.frameup"
    bl_label = "Move current frame by X"
    
    def execute(self, context):
        global frame_up
        bpy.data.scenes["Scene"].frame_current = bpy.data.scenes["Scene"].frame_current + frame_up
        return {'FINISHED'}

class OBJECT_OT_FrameDown(bpy.types.Operator):
    """Tooltip"""
    bl_idname = "animationcontroller.framedown"
    bl_label = "Move current frame by X"
    
    def execute(self, context):
        global frame_up
        bpy.data.scenes["Scene"].frame_current = bpy.data.scenes["Scene"].frame_current - frame_up
        return {'FINISHED'}

class OBJECT_OT_FrameOneTenToggle(bpy.types.Operator):
    """Tooltip"""
    bl_idname = "animationcontroller.frame_onetentoggle"
    bl_label = "Toggle frame advancement rate"
    
    def execute(self, context):
        global frame_up
        if frame_up == 10:
            frame_up = 1
        else:
            frame_up = 10
        return {'FINISHED'}

class OBJECT_OT_FrameOneTwoToggle(bpy.types.Operator):
    """Tooltip"""
    bl_idname = "animationcontroller.frame_onetwotoggle"
    bl_label = "Toggle frame advancement rate"
    
    def execute(self, context):
        global frame_up
        if frame_up == 2:
            frame_up = 1
        else:
            frame_up = 2
        return {'FINISHED'}

addon_keymaps = []

def register():
    bpy.utils.register_class(OBJECT_OT_SetOnion)
    bpy.utils.register_class(OBJECT_OT_FrameUp)
    bpy.utils.register_class(OBJECT_OT_FrameDown)
    bpy.utils.register_class(OBJECT_OT_FrameOneTenToggle)
    bpy.utils.register_class(OBJECT_OT_FrameOneTwoToggle)
    wm = bpy.context.window_manager
    kc = wm.keyconfigs.addon
    if kc:
        km = wm.keyconfigs.addon.keymaps.new(name='3D View', space_type='VIEW_3D')
        kmi = km.keymap_items.new(OBJECT_OT_SetOnion.bl_idname, type='F9', value='PRESS', ctrl=True, shift=True, alt=True)
        addon_keymaps.append((km, kmi))
        kmi = km.keymap_items.new(OBJECT_OT_FrameUp.bl_idname, type='F1', value='PRESS', ctrl=True, shift=True, alt=True)
        addon_keymaps.append((km, kmi))
        kmi = km.keymap_items.new(OBJECT_OT_FrameDown.bl_idname, type='F2', value='PRESS', ctrl=True, shift=True, alt=True)
        addon_keymaps.append((km, kmi))
        kmi = km.keymap_items.new(OBJECT_OT_FrameOneTenToggle.bl_idname, type='F3', value='PRESS', ctrl=True, shift=True, alt=True)
        addon_keymaps.append((km, kmi))
        kmi = km.keymap_items.new(OBJECT_OT_FrameOneTwoToggle.bl_idname, type='F4', value='PRESS', ctrl=True, shift=True, alt=True)
        addon_keymaps.append((km, kmi))


def unregister():
    bpy.utils.unregister_class(OBJECT_OT_SetOnion)
    bpy.utils.unregister_class(OBJECT_OT_FrameUp)
    bpy.utils.unregister_class(OBJECT_OT_FrameDown)
    bpy.utils.unregister_class(OBJECT_OT_FrameOneTenToggle)
    bpy.utils.unregister_class(OBJECT_OT_FrameOneTwoToggle)
    for km, kmi in addon_keymaps:
        km.keymap_items.remove(kmi)
    addon_keymaps.clear()


if __name__ == "__main__":
    register()
