/*
 * LX preview module
 *
 * Copyright (c) 2008-2022 The Foundry Group LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.   Except as contained
 * in this notice, the name(s) of the above copyright holders shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef LX_preview_H
#define LX_preview_H

typedef struct vt_ILxPreviewService ** ILxPreviewServiceID;
typedef struct vt_ILxPreview ** ILxPreviewID;
typedef struct vt_ILxPreviewNotifier ** ILxPreviewNotifierID;

#include <lxrender.h>



typedef struct vt_ILxPreviewService {
        ILxUnknown	 iunk;
        LXxMETHOD (   LxResult,
CreatePreview) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD (	LxResult,
GetMeshPreview) (
        LXtObjectID		  self,
        LXtObjectID		  item,
        int			  width,
        int			  height,
        void			**ppvObj);
} ILxPreviewService;

/*
 * The first method will start a Preview rendering. The Preview could either be stopped
 * or paused. If it's neither, this will have no effect.
 * 
 * And this method will stop it.
 * 
 * Alternatively, we can pause the Preview. This stops rendering, but a future start
 * will not clear the image and will resume where it left off, unless the scene has
 * been updated.
 * 
 * This function will both set Preview such that the next time it starts, it will
 * do a full update, completely rebuilding all the render data and tableau from
 * scratch.
 * 
 * This method is used to set the resolution of a Preview render. If Preview is currently
 * rendering, it will stop and restart Preview once it has updated the resolution.
 * 
 * Sets what time to render at. Currently this calls select.time but might change in future to render at a different time
 * 
 * 
 * This method is used to set the quality of a Preview render.
 * 
 * Sets whether to render motion blur or not
 * 
 * Sets whether to render all outputs or just do a final color output
 * 
 * Sets whether to use all threads or not.
 * 
 * Set whether the Preview should render in stereo or not.
 * 
 * This function takes a ILxPreviewNotifier object, which will get notified when a new image is available.
 * 
 * Sets if Preview should set the alpha channel
 * 
 * Is used to enable/disable per preview camera overrides.
 * If enabled, preview specific camera attributes will be used in place
 * of attributes specific by a camera item in the scene. If disabled then the camera
 * attributes are got from a camera item.
 * Camera overrides allow us to change the camera settings
 * without changing the scene itself. The settings are per preview and so
 * do not affect any other views of the Cinema.
 * The SetCameraOverride set of preview methods are used
 * for setting these preview specific fields.
 * 
 * 
 * Sets the camera matrix.
 * This will only be used when 'UseCameraOverride'
 * is enabled.
 * 
 * Sets the field of view for a camera
 * that is tied only to the preview. Setting this
 * will not change the state of any camera items.
 * 
 * Sets the horizontal aperture for a camera
 * that is tied only to the preview. Setting this
 * will not change the state of any camera items.
 * 
 * Sets the vertical aperture for a camera
 * that is tied only to the preview. Setting this
 * will not change the state of any camera items.
 * 
 * Sets the projection type of a camera
 * that is tied only to the preview. Setting this
 * will not change the state of any camera items.
 * The projection type can be set to one of
 * the following integers:
 * PERSP           0
 * ORTHO           1
 * CYLINDRICAL     2
 * SPHERICAL       3
 * 
 * 
 * Get the current resolution width of a Preview render.
 * 
 * Get the current resolution height of a Preview render.
 * 
 * Returns what frame preview is currently being rendered.
 * 
 * Query whether the render is complete. It returns LXe_TRUE or LXe_FALSE.
 * 
 * Get the current state of the rendering image. The client must release
 * this object once it's done.
 * 
 * Limit preview to render a specific shading effect.
 * 
 * Set preview to render in baking mode
 * 
 * A specific texture layer can also be used to limit shading
 * effects to only the layers below it.  This is useful for baking.
 * 
 * Get the current progress amount for a preview client.
 * 
 * Certain selection events can be ignored.
 * 
 * Query whether the render completed successfully or was stopped. It returns LXe_TRUE 
 * if the render finished successfully or LXe_FALSE if the render was stopped or is still running.
 */
typedef struct vt_ILxPreview {
        ILxUnknown	 iunk;
        LXxMETHOD (	LxResult,
Start) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
Stop) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
Pause) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
Reset) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
SetRes) (
        LXtObjectID		  self,
        int			  width,
        int			  height);
        LXxMETHOD (	LxResult,
SetRenderTime) (
        LXtObjectID		  self,
        double			  time );
        LXxMETHOD (	LxResult,
SetQuality) (
        LXtObjectID		  self,
        int			  quality,
        int			  samples);
        LXxMETHOD ( LxResult,
SetMotionBlur) (
        LXtObjectID		  self,
        int			  enable);
        LXxMETHOD (	LxResult,
SetRenderAllOutputs) (
        LXtObjectID		  self,
        int			  enable);
        LXxMETHOD (	LxResult,
SetUseAllThreads) (
        LXtObjectID		  self,
        int			  enable);
        LXxMETHOD (	LxResult,
SetStereo) (
        LXtObjectID		  self,
        int			  enable,
        int			  eye);
        LXxMETHOD (	LxResult,
SetNotifier) (
        LXtObjectID		self,
        LXtObjectID		notifier);
        LXxMETHOD (	LxResult,
SetAlpha) (
        LXtObjectID		self,
        int			enable );
  LXxMETHOD (	LxResult,
UseCameraOverride) (
        LXtObjectID		self,
        int			useCameraOverride);
  LXxMETHOD (	LxResult,
SetCameraOverrideTransform) (
        LXtObjectID		self,
        const LXtMatrix4 transform);
  LXxMETHOD (	LxResult,
SetCameraOverrideFocalLength) (
        LXtObjectID	self,
        float		focalLength);
  LXxMETHOD (	LxResult,
SetCameraOverrideApertureX) (
        LXtObjectID	self,
        float		apertureX);
  LXxMETHOD (	LxResult,
SetCameraOverrideApertureY) (
        LXtObjectID	self,
        float		apertureY);
  LXxMETHOD (	LxResult,
SetCameraOverrideProjectionType) (
        LXtObjectID	self,
        int		projectionType);
        LXxMETHOD (	int,
GetResWidth) (
        LXtObjectID		  self );
        LXxMETHOD (	int,
GetResHeight) (
        LXtObjectID		  self );
        LXxMETHOD (	double,
GetCurrentTime) (
        LXtObjectID		  self );
        LXxMETHOD (	LxResult,
IsComplete) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
GetBuffer) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD (	LxResult,
SetEffect) (
        LXtObjectID		  self,
        const char		 *effect);
        LXxMETHOD (	LxResult,
SetBakeMode) (
        LXtObjectID		  self,
        int			  mode);
        LXxMETHOD (	LxResult,
SetLastTexture) (
        LXtObjectID		  self,
        LXtObjectID		  item);
        LXxMETHOD (	float,
GetProgress) (
        LXtObjectID		  self);
        LXxMETHOD (	void,
SetIgnoreSelections)  (
        LXtObjectID		  self,
        int			  allow);
        LXxMETHOD (	LxResult,
IsFinished) (
        LXtObjectID		  self);
} ILxPreview;

typedef struct vt_ILxPreviewNotifier {
        ILxUnknown	 iunk;
        LXxMETHOD (	LxResult,
Notify) (
        LXtObjectID			 self,
        const LXtRenderOutputProcess	*rndrProcess,
        LXtObjectID			 image,
        int				 completed );
} ILxPreviewNotifier;

/*
 * The Preview SDK API allows a plug-in to create and perform headless, interactive
 * Preview renders.
 * The Preview service is solely for the purpose of creating a preview object.
 */

        #define LXu_PREVIEWSERVICE	 "0491f901-6eee-48e4-a4d0-b2e6d10624b6"
        #define LXa_PREVIEWSERVICE	 "previewservice"
        // [local]  ILxPreviewService
        // [python] ILxPreviewService:CreatePreview	obj Preview

/*
 * The Preview object is where all the interesting things happen.
 */

        #define LXu_PREVIEW		"6817942a-375d-485f-b927-af93d1391d73"
        #define LXa_PREVIEW		"preview"
        // [local] ILxPreview
        // [const] ILxPreview:Start
        // [const] ILxPreview:Stop
        // [const] ILxPreview:Pause
        // [const] ILxPreview:Reset
        // [const] ILxPreview:SetRes
        // [const] ILxPreview:SetQuality
        // [const] ILxPreview:SetRenderAllOutputs
        // [const] ILxPreview:SetStereo 
        // [const] ILxPreview:IsComplete
        // [const] ILxPreview:GetBuffer
        // [const] ILxPreview:SetUseAllThreads
        // [const] ILxPreview:SetEffect
        // [const] ILxPreview:SetBakeMode
        // [const] ILxPreview:SetPreviewTexture
        // [const] ILxPreview:SetLastTexture
        // [const] ILxPreview:GetProgress
        // [const] ILxPreview:SetIgnoreSelections
        // [const] ILxPreview:IsFinished

        // [python] ILxPreview:IsComplete		bool
        // [python] ILxPreview:GetBuffer		obj Image

/*
 * It also takes in the number of average AA samples to be fired per pixel. If the value is zero
 * or negative, it will use the default values. Typically this is something like
 * MAX (64, renderSettings) for draft mode, renderSettings for final mode, and some really high
 * number (currently 16384) for extended mode.
 */

        #define LXiPREVIEW_DRAFT_QUALITY		0
        #define LXiPREVIEW_FINAL_QUALITY		1
        #define LXiPREVIEW_EXTENDED_QUALITY		2

/*
 * This is the PreviewNotifier interface class that users can implement to get notified when a preview image
 * is availble.
 */

        #define LXu_PREVIEWNOTIFIER		"352039c2-8b70-46db-9a83-1e05fd887fc0"
        #define LXa_PREVIEWNOTIFIER		"previewnotifier"
        // [local] ILxPreviewNotifier
        // [export] ILxPreviewNotifier ntf

#endif
