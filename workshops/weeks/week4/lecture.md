### Member Functions

functions with an association with an object
They have access to object properties and can modify their values.
there are three classes of membersfunctions
- Queries (const)
- Modifiers
- Specials


const protects values inside an object from modifications (direct access or other modif function calls)


### Struct access
making different parts of the struct public or private

```cpp
struct demo{
    private:
        int x;
        int y;
    public:
        void setX();
        void setY();
}
```

```cpp
struct demo{
    void setX();
    void setY();
    private:
        int x;
        int y;
}
```


## Classes
the difference is everything is private by default. thats it!

```cpp
class test{
    int x;
    int y;
    public:
        void setX();
        void setY();
}
```

### special functions
are dedicated to destruction and contruction of an object of a class.
default contructor function - looks like the name of the object like :`type();`
are being called when the object is initiated

also the `destructor` which would be called when the object would be out of scope.
```cpp
playdoh.~playdoh(){
    ...
}
```
note: the main purpos of this functions are in case of timings.
note: which object has been mad earlier would be destroyd later and reverse.

### `new` keyword

which would help us to make objects using dynamic memory

```cpp
playdoh* parr = nullptr //this would not call any constructor
parr = new playdoh[3]; //this would call the contructor 3 times

// ![not finished]

```

to recap:
#### typical time line
    1. constructors are called
    2. destructors are called
    3. allocated memory is released

and the order of destructors are reversed.

**constructors can accept arguments as well**
