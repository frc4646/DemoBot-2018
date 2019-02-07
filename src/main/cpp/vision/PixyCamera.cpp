/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "vision/PixyCamera.h"
#include <iostream>
#include "commands/PixyDemoTrack.h"
#include <iostream>

PixyCamera::PixyCamera() : Subsystem("PixyCamera") {
    pan = new Servo(7);
    tilt = new Servo(8);
    pixy.init();
    index =-1;
    panLoop = new PIDLoop(400, 0, 400, true);
    tiltLoop = new PIDLoop(500, 0, 500, true);
    printf("Pixy initialized successfully!");
    //pixy.setServos(500, 500);
    pan->Set(.5);
    tilt->Set(.5);
    pixy.changeProg("color_connected_components");
    
}
void PixyCamera::InitDefaultCommand() {
   SetDefaultCommand(new PixyDemoTrack());
}

Pixy2 PixyCamera::getPixy(){
    return pixy;
}

// Take the biggest block (blocks[0]) that's been around for at least 30 frames (1/2 second)
// and return its index, otherwise return -1
int16_t PixyCamera::acquireBlock()
{
  if (pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_age>30)
    return pixy.ccc.blocks[0].m_index;

  return -1;
}

// Find the block with the given index.  In other words, find the same object in the current
// frame -- not the biggest object, but he object we've locked onto in acquireBlock()
// If it's not in the current frame, return NULL
Block *PixyCamera::trackBlock(uint8_t ind)
{
  uint8_t i;

  for (i=0; i<pixy.ccc.numBlocks; i++)
  {
    if (ind==pixy.ccc.blocks[i].m_index)
      return &pixy.ccc.blocks[i];
  }

  return NULL;
}

Block PixyCamera::trackOrangeBall(){
    // use ccc program to track objects
    Block *block = NULL;
    int32_t panOffset, tiltOffset;
    
    
    pixy.ccc.getBlocks(false, 1, 1);
    if (index == -1){
        index = acquireBlock();
    }
    // If we've found a block, find it, track it
    if (index>=0)
      block = trackBlock(index);
      //printf("Found target!");
    
    if (block)
    {   
      panOffset = (int32_t)pixy.frameWidth/2 - (int32_t)block->m_x;
      tiltOffset = (int32_t)block->m_y - (int32_t)pixy.frameHeight/2;  
  
      panLoop->update(panOffset);
      tiltLoop->update(tiltOffset);
    
      pan->Set(panLoop->m_command/1000.0);
      tilt->Set(tiltLoop->m_command/1000.0);
      //tilt->Set(.5);
      //printf("Pan: %f \n", panLoop->m_command/1000.0);
      //printf("Tilt: %f \n", tiltLoop->m_command/1000.0);
      //pixy.setServos(panLoop->m_command, tiltLoop->m_command);
    }
    else // no object detected, go into reset state
    {
      panLoop->reset();
      tiltLoop->reset();
      //pixy.setServos(panLoop->m_command, tiltLoop->m_command);
      pan->Set(0.5);
      tilt->Set(0.5);
      index = -1;
      //printf("no object \n");
    }

}

Block PixyCamera::trackVisionTarget(){
    // use ccc program to track objects
    pixy.changeProg("line");
}


