#ifndef __LIBPULSE_H_
#define __LIBPULSE_H_ 

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


enum    pa_context_state {
    PA_CONTEXT_UNCONNECTED,
    PA_CONTEXT_CONNECTING,
    PA_CONTEXT_AUTHORIZING,
    PA_CONTEXT_SETTING_NAME,
    PA_CONTEXT_READY,
    PA_CONTEXT_FAILED,
    PA_CONTEXT_TERMINATED
};
typedef enum pa_context_state  pa_context_state_t;

enum  	pa_operation_state {
  PA_OPERATION_RUNNING,
  PA_OPERATION_DONE,
  PA_OPERATION_CANCELLED
};

typedef enum pa_operation_state 	pa_operation_state_t;

typedef struct pa_spawn_api {
    void (*prefork)(void);
    void (*postfork)(void);
    void (*atfork)(void);
} pa_spawn_api;


typedef enum pa_subscription_mask {
    PA_SUBSCRIPTION_MASK_NULL = 0x0000U,
    /**< No events */

    PA_SUBSCRIPTION_MASK_SINK = 0x0001U,
    /**< Sink events */

    PA_SUBSCRIPTION_MASK_SOURCE = 0x0002U,
    /**< Source events */

    PA_SUBSCRIPTION_MASK_SINK_INPUT = 0x0004U,
    /**< Sink input events */

    PA_SUBSCRIPTION_MASK_SOURCE_OUTPUT = 0x0008U,
    /**< Source output events */

    PA_SUBSCRIPTION_MASK_MODULE = 0x0010U,
    /**< Module events */

    PA_SUBSCRIPTION_MASK_CLIENT = 0x0020U,
    /**< Client events */

    PA_SUBSCRIPTION_MASK_SAMPLE_CACHE = 0x0040U,
    /**< Sample cache events */

    PA_SUBSCRIPTION_MASK_SERVER = 0x0080U,
    /**< Other global server changes. */

/** \cond fulldocs */
    PA_SUBSCRIPTION_MASK_AUTOLOAD = 0x0100U,
    /**< \deprecated Autoload table events. */
/** \endcond */

    PA_SUBSCRIPTION_MASK_CARD = 0x0200U,
    /**< Card events. \since 0.9.15 */

    PA_SUBSCRIPTION_MASK_ALL = 0x02ffU
    /**< Catch all events */
} pa_subscription_mask_t;

enum  	pa_subscription_event_type {
  PA_SUBSCRIPTION_EVENT_SINK = 0x0000U,
  PA_SUBSCRIPTION_EVENT_SOURCE = 0x0001U,
  PA_SUBSCRIPTION_EVENT_SINK_INPUT = 0x0002U,
  PA_SUBSCRIPTION_EVENT_SOURCE_OUTPUT = 0x0003U,
  PA_SUBSCRIPTION_EVENT_MODULE = 0x0004U,
  PA_SUBSCRIPTION_EVENT_CLIENT = 0x0005U,
  PA_SUBSCRIPTION_EVENT_SAMPLE_CACHE = 0x0006U,
  PA_SUBSCRIPTION_EVENT_SERVER = 0x0007U,
  PA_SUBSCRIPTION_EVENT_CARD = 0x0009U,
  PA_SUBSCRIPTION_EVENT_FACILITY_MASK = 0x000FU,
  PA_SUBSCRIPTION_EVENT_NEW = 0x0000U,
  PA_SUBSCRIPTION_EVENT_CHANGE = 0x0010U,
  PA_SUBSCRIPTION_EVENT_REMOVE = 0x0020U,
  PA_SUBSCRIPTION_EVENT_TYPE_MASK = 0x0030U
};

#endif
