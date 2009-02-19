/**
  src/library_entry_point.c
  
  The library entry point. It must have the same name for each
  library of the components loaded by the ST static component loader.
  This function fills the version, the component name and if existing also the roles
  and the specific names for each role. This base function is only an explanation.
  For each library it must be implemented, and it must fill data of any component
  in the library
  
  Copyright (C) 2007-2009 STMicroelectronics
  Copyright (C) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).

  This library is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation; either version 2.1 of the License, or (at your option)
  any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
  details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St, Fifth Floor, Boston, MA
  02110-1301  USA
  
  $Date$
  Revision $Rev$
  Author $Author$

*/

#include <bellagio/st_static_component_loader.h>
#include <omx_jpegenc_component.h>
#include <omx_jpegdec_component.h>

/** The library entry point. It must have the same name for each
 * library of the components loaded by the ST static component loader.
 * 
 * This function fills the version, the component name and if existing also the roles
 * and the specific names for each role. This base function is only an explanation.
 * For each library it must be implemented, and it must fill data of any component
 * in the library
 * 
 * @param stComponents pointer to an array of components descriptors.If NULL, the 
 * function will return only the number of components contained in the library
 * 
 * @return number of components contained in the library 
 */
int omx_component_library_Setup(stLoaderComponentType **stComponents) {
  DEBUG(DEB_LEV_FUNCTION_NAME, "In %s \n",__func__);
  if (stComponents == NULL) {
    DEBUG(DEB_LEV_FUNCTION_NAME, "Out of %s \n",__func__);
    return 2; // Return Number of Component/s
  }
  stComponents[0]->componentVersion.s.nVersionMajor = 1; 
  stComponents[0]->componentVersion.s.nVersionMinor = 1; 
  stComponents[0]->componentVersion.s.nRevision = 1;
  stComponents[0]->componentVersion.s.nStep = 1;

  stComponents[0]->name = calloc(1,OMX_MAX_STRINGNAME_SIZE);
  if (stComponents[0]->name == NULL) {
    return OMX_ErrorInsufficientResources;
  }
  strcpy(stComponents[0]->name, "OMX.st.image_decoder.jpeg");
  stComponents[0]->name_specific_length = 1; 
  stComponents[0]->constructor = omx_jpegdec_component_Constructor;  
  
  stComponents[0]->name_specific = calloc(stComponents[0]->name_specific_length,sizeof(char *));  
  stComponents[0]->role_specific = calloc(stComponents[0]->name_specific_length,sizeof(char *));  

  stComponents[0]->name_specific[0] = calloc(1,OMX_MAX_STRINGNAME_SIZE);
  if (stComponents[0]->name_specific[0] == NULL) {
    return OMX_ErrorInsufficientResources;
  }
  stComponents[0]->role_specific[0] = calloc(1,OMX_MAX_STRINGNAME_SIZE);
  if (stComponents[0]->role_specific[0] == NULL) {
    return OMX_ErrorInsufficientResources;
  }

  strcpy(stComponents[0]->name_specific[0], "OMX.st.image_decoder.jpeg");
  strcpy(stComponents[0]->role_specific[0], "image_decoder.jpeg");

  stComponents[1]->componentVersion.s.nVersionMajor = 1; 
  stComponents[1]->componentVersion.s.nVersionMinor = 1; 
  stComponents[1]->componentVersion.s.nRevision = 1;
  stComponents[1]->componentVersion.s.nStep = 1;

  stComponents[1]->name = calloc(1,OMX_MAX_STRINGNAME_SIZE);
  if (stComponents[1]->name == NULL) {
    return OMX_ErrorInsufficientResources;
  }
  strcpy(stComponents[1]->name, "OMX.st.image_encoder.jpeg");
  stComponents[1]->name_specific_length = 1; 
  stComponents[1]->constructor = omx_jpegenc_component_Constructor;  
  
  stComponents[1]->name_specific = calloc(stComponents[1]->name_specific_length,sizeof(char *));  
  stComponents[1]->role_specific = calloc(stComponents[1]->name_specific_length,sizeof(char *));  

  stComponents[1]->name_specific[0] = calloc(1,OMX_MAX_STRINGNAME_SIZE);
  if (stComponents[1]->name_specific[0] == NULL) {
    return OMX_ErrorInsufficientResources;
  }
  stComponents[1]->role_specific[0] = calloc(1,OMX_MAX_STRINGNAME_SIZE);
  if (stComponents[1]->role_specific[0] == NULL) {
    return OMX_ErrorInsufficientResources;
  }

  strcpy(stComponents[1]->name_specific[0], "OMX.st.image_encoder.jpeg");
  strcpy(stComponents[1]->role_specific[0], "image_encoder.jpeg");

  DEBUG(DEB_LEV_FUNCTION_NAME, "Out of %s \n",__func__);
  return 2;
}
