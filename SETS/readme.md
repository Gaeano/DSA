## This  assignment is where the sets are all initialized to 0. Making its function for adding a value only initialize it to 1 to its specific position
### to add a value to a set not initialized to 0

```C
#define BITS (sizeof(char) * 8)
void setAnswer(Set* profile, int index, int value){
    if (value == 1){
    profile->answers[index / BITS] |= (1 << (index % BITS); // assign to one
    } else {
    profile->answers[index/BITS] &= ~( 1 << (index & BITS));
    }
  }
}
```
