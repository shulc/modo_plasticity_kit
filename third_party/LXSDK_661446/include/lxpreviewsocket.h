/*
 * LX previewsocket module
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
#ifndef LX_previewsocket_H
#define LX_previewsocket_H



/*
 * These codes are used to identify any data sent to or from the preview socket, and
 * are used to prefix the packet.  
 * For the most part, the remote host (Remote) sends request messages to the preview
 * server (Preview). Preivew then sends back acknowledgements or errors.  Every message
 * sent by Remote will have a matching response from Preview.
 * Unless otherwise specified, requests apply to protocol 0.  Higher protocol numbers
 * tend to support all of the previous protocol's features as well as adding new ones.
 * Messages that require a specific protocol or greater are mentioned in the comments.
 * Note that sending a packet that is not supported by a specific protocol version will
 * result in an error, usually followed by a disconnect (as there is no way to know how
 * long the unrecognized packet is so that it can be skipped).
 * 
 */

        #define	LXfPREVIEWMSG_REQ				0x10000000
        #define	LXfPREVIEWMSG_ACK				0x20000000

        #define LXiPREVIEWMSG_ACK_ERROR				(LXfPREVIEWMSG_ACK | 0x01000000)

        // Initial Setup
        #define	LXiPREVIEWMSG_REQ_SET_PROTOCOL			(LXfPREVIEWMSG_REQ | 0x00001000)
        #define	LXiPREVIEWMSG_ACK_PROTOCOL_SET			(LXfPREVIEWMSG_ACK | 0x00001000)

        // Image Property Setup
        #define	LXiPREVIEWMSG_REQ_SET_RES			(LXfPREVIEWMSG_REQ | 0x00002000)
        #define	LXiPREVIEWMSG_ACK_RES_SET			(LXfPREVIEWMSG_ACK | 0x00002000)

        #define	LXiPREVIEWMSG_REQ_SET_FORMAT			(LXfPREVIEWMSG_REQ | 0x00002001)
        #define	LXiPREVIEWMSG_ACK_FORMAT_SET			(LXfPREVIEWMSG_ACK | 0x00002001)

        #define	LXiPREVIEWMSG_REQ_SET_STEREO			(LXfPREVIEWMSG_REQ | 0x00002002)
        #define	LXiPREVIEWMSG_ACK_STEREO_SET			(LXfPREVIEWMSG_ACK | 0x00002002)

        #define	LXiPREVIEWMSG_REQ_SET_SAMPLES			(LXfPREVIEWMSG_REQ | 0x00002003)
        #define	LXiPREVIEWMSG_ACK_SAMPLES_SET			(LXfPREVIEWMSG_ACK | 0x00002003)

        #define	LXiPREVIEWMSG_REQ_SET_DRAFT			(LXfPREVIEWMSG_REQ | 0x00002004)
        #define	LXiPREVIEWMSG_ACK_DRAFT_SET			(LXfPREVIEWMSG_ACK | 0x00002004)

        #define	LXiPREVIEWMSG_REQ_SET_FINAL			(LXfPREVIEWMSG_REQ | 0x00002005)
        #define	LXiPREVIEWMSG_ACK_FINAL_SET			(LXfPREVIEWMSG_ACK | 0x00002005)

        #define	LXiPREVIEWMSG_REQ_SET_EXTENDED			(LXfPREVIEWMSG_REQ | 0x00002006)
        #define	LXiPREVIEWMSG_ACK_EXTENDED_SET			(LXfPREVIEWMSG_ACK | 0x00002006)

        #define	LXiPREVIEWMSG_REQ_SET_EFFECT			(LXfPREVIEWMSG_REQ | 0x00002007)
        #define	LXiPREVIEWMSG_ACK_EFFECT_SET			(LXfPREVIEWMSG_ACK | 0x00002007)

        #define	LXiPREVIEWMSG_REQ_SET_MOUSEPOS			(LXfPREVIEWMSG_REQ | 0x00002008)
        #define	LXiPREVIEWMSG_ACK_MOUSEPOS_SET			(LXfPREVIEWMSG_ACK | 0x00002008)

        #define	LXiPREVIEWMSG_REQ_SET_CAMERA			(LXfPREVIEWMSG_REQ | 0x00002009)
        #define	LXiPREVIEWMSG_ACK_CAMERA_SET			(LXfPREVIEWMSG_ACK | 0x00002009)

        #define	LXiPREVIEWMSG_REQ_SET_COMPRESS			(LXfPREVIEWMSG_REQ | 0x0000200A)		// Protocol version 1 and above
        #define	LXiPREVIEWMSG_ACK_COMPRESS_SET			(LXfPREVIEWMSG_ACK | 0x0000200A)		// Protocol version 1 and above

        #define	LXiPREVIEWMSG_COMPRESS_NONE					     0x00000000
        #define	LXiPREVIEWMSG_COMPRESS_PNG					     0x00000001

        // Frame Requests
        #define	LXiPREVIEWMSG_REQ_SEND_FULL_FRAME		(LXfPREVIEWMSG_REQ | 0x00003000)
        #define	LXiPREVIEWMSG_ACK_SEND_FULL_FRAME		(LXfPREVIEWMSG_ACK | 0x00003000)

        #define	LXiPREVIEWMSG_PREVIEW_UNAVAILABLE				     0x00000001
        #define	LXiPREVIEWMSG_PREVIEW_RGBAFP					     0x00000002
        #define	LXiPREVIEWMSG_PREVIEW_COMPLETE					     0x00000100
        #define	LXiPREVIEWMSG_PREVIEW_COMPRESSED				     0x00000200

        #define	LXiPREVIEWMSG_ACK_SEND_FULL_FRAME_RGB24		(LXiPREVIEWMSG_ACK_SEND_FULL_FRAME)
        #define	LXiPREVIEWMSG_ACK_SEND_FULL_FRAME_RGBAFP	(LXiPREVIEWMSG_ACK_SEND_FULL_FRAME | LXiPREVIEWMSG_PREVIEW_RGBAFP)
        #define	LXiPREVIEWMSG_ACK_FULL_FRAME_UNAVAILABLE	(LXiPREVIEWMSG_ACK_SEND_FULL_FRAME | LXiPREVIEWMSG_PREVIEW_UNAVAILABLE)
        #define	LXiPREVIEWMSG_ACK_FULL_FRAME_DONE		(LXiPREVIEWMSG_ACK_FULL_FRAME_UNAVAILABLE | LXiPREVIEWMSG_PREVIEW_COMPLETE)

        // Preview image ID
        #define	LXiPREVIEWMSG_REQ_GET_ID			(LXfPREVIEWMSG_REQ | 0x00004000)
        #define	LXiPREVIEWMSG_ACK_ID_GET			(LXfPREVIEWMSG_ACK | 0x00004000)

        // Progress status
        #define	LXiPREVIEWMSG_REQ_GET_PROGRESS			(LXfPREVIEWMSG_REQ | 0x00008000)
        #define	LXiPREVIEWMSG_ACK_PROGRESS_GET			(LXfPREVIEWMSG_ACK | 0x00008000)

#endif
