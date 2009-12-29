//****************************************************************************/
//  File:   PSRampShot.h
//  Date:   12.07.2006
//  Author: Ruslan Shestopalyuk
//****************************************************************************/
#ifndef __PSRampShot_H__
#define __PSRampShot_H__

//****************************************************************************/
//  Class:  PSRampShot
//  Desc:   Base class for particle system operators
//****************************************************************************/
class PSRampShot : public PSOperator
{
public: 
    PSRampShot();

    expose( PSRampShot )
    {
        parent(PSOperator);
    }
}; // class PSRampShot

#endif // __PSRampShot_H__


