#ifndef __LIBPULSE_H_
#define __LIBPULSE_H_ 

#define NOT_IMPLEMENTED(f) int f(){ printf("NOT IMPLEMENTED:" #f  "\n"); };

typedef struct pa_mainloop_api{
    void *userdata;

    void* (*io_new)();
    void (*io_enable)();
    void (*io_free)();
    void (*io_set_destroy)();

    void* (*time_new)();
    void (*time_restart)();
    void (*time_free)();
    void (*time_set_destroy)();
    
    void* (*defer_new)();
    void (*defer_enable)();
    void (*defer_free)();
    void (*defer_set_destroy)();

    void (*quit)();

    void* (*rtclock_time_new)();
    void (*rtclock_time_restart)();
} pa_mainloop_api;


typedef void(* pa_context_notify_cb_t)(int *c, void *userdata);


typedef enum pa_sample_format {
    PA_SAMPLE_U8,
    PA_SAMPLE_ALAW,
    PA_SAMPLE_ULAW,
    PA_SAMPLE_S16LE,
    PA_SAMPLE_S16BE,
    PA_SAMPLE_FLOAT32LE,
    PA_SAMPLE_FLOAT32BE,
    PA_SAMPLE_S32LE,
    PA_SAMPLE_S32BE,
    PA_SAMPLE_S24LE,
    PA_SAMPLE_S24BE,
    PA_SAMPLE_S24_32LE,
    PA_SAMPLE_S24_32BE,
    PA_SAMPLE_MAX,
    PA_SAMPLE_INVALID = -1
} pa_sample_format_t;

static const size_t size_table[] = {
    [PA_SAMPLE_U8] = 1,
    [PA_SAMPLE_ULAW] = 1,
    [PA_SAMPLE_ALAW] = 1,
    [PA_SAMPLE_S16LE] = 2,
    [PA_SAMPLE_S16BE] = 2,
    [PA_SAMPLE_FLOAT32LE] = 4,
    [PA_SAMPLE_FLOAT32BE] = 4,
    [PA_SAMPLE_S32LE] = 4,
    [PA_SAMPLE_S32BE] = 4,
    [PA_SAMPLE_S24LE] = 3,
    [PA_SAMPLE_S24BE] = 3,
    [PA_SAMPLE_S24_32LE] = 4,
    [PA_SAMPLE_S24_32BE] = 4
};

typedef struct why_buffer{
    char *buffer;
    size_t buffer_size;
    pthread_mutex_t mutex;
    size_t tail;
} why_buffer;

typedef struct pa_sample_spec {
    pa_sample_format_t format;
    uint32_t rate;
    uint8_t channels;
} pa_sample_spec;

typedef struct pa_channel_map {
    uint8_t channels;
    int map[32];
} pa_channel_map;

typedef struct stream stream_t;


 typedef struct pa_buffer_attr {
    uint32_t maxlength;
    uint32_t tlength;
    uint32_t prebuf;
    uint32_t minreq;
    uint32_t fragsize;
} pa_buffer_attr;

typedef void(* pa_stream_notify_cb_t)(stream_t* p, void *userdata);
typedef void(* pa_stream_request_cb_t)(stream_t *p, size_t nbytes, void *userdata);

struct stream {
    int fd;
    int running;
    pthread_t thread;
    pa_stream_request_cb_t write_callback;
    void* write_userdata;
    pa_stream_request_cb_t read_callback;
    void* read_userdata;
    pa_stream_notify_cb_t notify_callback;
    void* notify_userdata;
    pa_stream_notify_cb_t underflow_callback;
    void* underflow_userdata;
    pa_sample_spec sample_spec;
    pa_buffer_attr buffer_attr;
    why_buffer* buffer;
    char name[200];
    int corked;
};

typedef enum pa_stream_state pa_stream_state_t;
enum  	pa_stream_state {
  PA_STREAM_UNCONNECTED,
  PA_STREAM_CREATING,
  PA_STREAM_READY,
  PA_STREAM_FAILED,
  PA_STREAM_TERMINATED
};

typedef void(* pa_stream_success_cb_t)(stream_t *s, int success, void *userdata);

enum  	pa_seek_mode {
  PA_SEEK_RELATIVE = 0,
  PA_SEEK_ABSOLUTE = 1,
  PA_SEEK_RELATIVE_ON_READ = 2,
  PA_SEEK_RELATIVE_END = 3
};

typedef enum pa_seek_mode pa_seek_mode_t;
typedef void* pa_free_cb_t;


#endif
