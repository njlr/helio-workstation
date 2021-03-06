/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

//[Headers]
#include "Common.h"
//[/Headers]

#include "SettingsRollover.h"

//[MiscUserDefs]
//[/MiscUserDefs]

SettingsRollover::SettingsRollover()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (225, 400);

    //[Constructor]
    //[/Constructor]
}

SettingsRollover::~SettingsRollover()
{
    //[Destructor_pre]
    //[/Destructor_pre]


    //[Destructor]
    //[/Destructor]
}

void SettingsRollover::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SettingsRollover::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}


//[MiscUserCode]
//[/MiscUserCode]

#if 0
/*
BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SettingsRollover" template="../../Template"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="225" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
