/// @description Play?

// fire and forget
// we get an instance of the event, play it, and then release
// FMOD will actually deallocate the instance from the memory once it stops playing.
sampleEvent.createInstance().start().release();
