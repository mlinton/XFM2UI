/********************
tiny time utils
Rui Azevedo - ruihfazevedo(@rrob@)gmail.com
*/

namespace TinyTimeUtils {

  //by default uses Arduino `millis` as time source
  constexpr auto timeSrc=millis;

  //time ticks as boolean
  template<int step>
  struct Tick {
    inline operator bool() {return timeSrc()>=next?next+=step,true:false;}
    inline void reset() {next=timeSrc()+step;}
    inline long when() const {return next;}
  protected:
    unsigned long next=0;
  };

  //FPS as boolean
  // this is an FPS limiter
  // will return `true` `fps` times per second (max)
  // note: this can skip a frame at timeSrc (millis) wrap (every 50days ;))
  template<int fps>
  struct FPS:public Tick<(1000/fps)> {};

  //blink without delay at a fixed rate (compile time defined)
  //just set the led state to this function output.
  template<int timeOn,int timeOff>
  inline bool sblink() {
    return timeSrc()%(unsigned long)(timeOn+timeOff)<(unsigned long)timeOn;
  }

  //blink without delay, just set the led state to this function output.
  //rate can be changed at runtime
  inline bool rblink(int timeOn,int timeOff) {
    return timeSrc()%(unsigned long)(timeOn+timeOff)<(unsigned long)timeOn;
  }
};