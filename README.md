# EMORY LIGHT MUSIC CONTROLER ASSIGNMENT
 
This is my assignment

## RESOURCES

- [User setup](userSetup.md)
- [User instructions](userControls.md)
- [Development documentation](developmentDocumentation.md)
- [Max patches](maxPatches)

###WHAT WORKED
- Controler was easy to implement as well as button combinations using gate
- LOTS of loadmess objects make it start in a reasonable place
- I think its pretty fun to use and really powerful

###WHAT DIDN'T WORK
- CPU requirement is huge, probably barely works on intel macs and certain windows machines
- Need further color control
- No accelerometer or gyroscope controls right now since didn't work with xbox controler I was using

###WORKFLOW
- I aproach using this patch by first selecting a video to use (DPAD LEFT and DPAD RIGHT) then deciding how much to mix with camera input or if I will use only one or the other (RIGHT TRIGGER + LEFT STICK)
- Then I quickly switch through different types of oscillators (Y and A) and the operation that occurs between the original video signal and the oscillator (DPAD DOWN and DPAD UP)
- I then usually adjust saturation and brightness to complement which oscillator and operation I decide on (RIGHT TRIGGER and RIGHT STICK)
- Then you can 