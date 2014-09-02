#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/soundcard.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>

#include "libpulse.h"

#define log empty_log /* Change this to printf to get some debug info */

static void empty_log(char* format, ...){
    
}

static int operation;

static pa_context_notify_cb_t state_callback;

static void *state_userdata;

void pa_context_set_state_callback (int* c, pa_context_notify_cb_t cb, void *userdata){
    state_callback = cb;
    state_userdata = userdata;
    log("pa_context_set_state_callback: Setting state callback\n");
}

static int in_thread=0;

static char version[1000]="no pulse, lol";

int* pa_cvolume_set(int* a,	unsigned  	channels, uint32_t v){
    log("pa_cvolume_set: not implemented\n");
}

void pa_threaded_mainloop_lock (int *m){
    log("pa_threaded_mainloop_lock: nothing to do\n");
}

void pa_threaded_mainloop_unlock (int *m){
    log("pa_threaded_mainloop_unlock: nothing to do\n");
}

int pa_threaded_mainloop_start(int *m) {
    log("pa_threaded_mainloop_start: nothing to do\n");
    return 0;
}

void pa_threaded_mainloop_wait(int* m){
    log("pa_threaded_mainloop_wait: waiting\n");
    usleep(10000);
}

const char* pa_get_library_version(void){
    log("Reporting version %s\n", version);
    return version;
}

void pa_threaded_mainloop_free(int *m){
    log("pa_threaded_mainloop_free: nothing to do\n");
}


static int context = 2;

int* pa_context_new  (  pa_mainloop_api *   mainloop, const char *    name  ){
    log("pa_context_new: mainloop_api=%p  and name=%s\n", mainloop, name); 
    return &context;
}

void pa_context_disconnect (int *c){
    log("pa_context_disconnec: nothing to do\n");
}

int* pa_context_drain(int *c, pa_context_notify_cb_t cb, void *userdata){
    log("pa_context_drain: not implemented\n");
    return NULL;
}

static int mainloop=1;

int* pa_threaded_mainloop_new  (void){
    log("pa_threaded_mainloop_new: Faking new mainloop\n");
    return &mainloop;
}

why_buffer* why_buffer_new(size_t size){
    why_buffer* b = (why_buffer*)malloc(sizeof(why_buffer));
    b->buffer = (char*)malloc(size);
    b->tail = 0;
    pthread_mutex_init(&b->mutex, NULL);
    return b;
}

void why_buffer_delete(why_buffer* b){
    pthread_mutex_destroy(&b->mutex);
    free(b->buffer);
    free(b);
}

void why_buffer_write(why_buffer* b, char* data, size_t size){
    pthread_mutex_lock(&b->mutex);
    memcpy(b->buffer+b->tail, data, size);
    b->tail+=size;
    pthread_mutex_unlock(&b->mutex);
}

size_t why_buffer_read(why_buffer* b, char* data){
    pthread_mutex_lock(&b->mutex);
    size_t n = b->tail;
    memcpy(data, b->buffer, b->tail);
    b->tail=0;
    pthread_mutex_unlock(&b->mutex);
    return n;
}


size_t pa_usec_to_bytes(uint64_t t, const pa_sample_spec *spec) {
    size_t res = (size_t) (((t * spec->rate) / 1000000ULL)) * (size_table[spec->format] * spec->channels);
    log("pa_usec_to_bytes usec=%llu  size=%zu \n", t, res);
    return res;
}

pa_channel_map* pa_channel_map_init_stereo(pa_channel_map *m){
    log("pa_channel_map_init_stereo:  Initializing stereo \n");
    m->channels = 2;
    m->map[0] = 1;
    m->map[1] = 2;
    return m;
}

pa_channel_map *pa_channel_map_init_mono(pa_channel_map *m){
    log("pa_channel_map_init_mono: Initializing mono \n");
    m->channels = 1;
    m->map[0] = 1;
    return m;
}


stream_t *pa_stream_new(int *c, const char *name, pa_sample_spec *ss, const pa_channel_map *map){
    log("pa_stream_new:   name=%s    sample_channels=%d     sample_rate=%d    sample_format=%d\n",  
           name, ss->channels, ss->rate, ss->format);
    stream_t* s = (stream_t*)malloc(sizeof(stream_t));
    if(name) strcpy(s->name, name); else strcpy(s->name, "default");
    s->sample_spec = *ss;
    s->corked=0;
    s->write_callback=NULL;
    s->read_callback=NULL;
    s->notify_callback=NULL;
    s->underflow_callback=NULL;
    return s;
}

int pa_sample_spec_valid(const pa_sample_spec *spec){
    log("pa_sample_spec_valid: reporting valid specification\n");
    return 1;
}

const char *pa_sample_format_to_string(pa_sample_format_t f) {
    static const char* const table[]= {
        [PA_SAMPLE_U8] = "u8",
        [PA_SAMPLE_ALAW] = "aLaw",
        [PA_SAMPLE_ULAW] = "uLaw",
        [PA_SAMPLE_S16LE] = "s16le",
        [PA_SAMPLE_S16BE] = "s16be",
        [PA_SAMPLE_FLOAT32LE] = "float32le",
        [PA_SAMPLE_FLOAT32BE] = "float32be",
        [PA_SAMPLE_S32LE] = "s32le",
        [PA_SAMPLE_S32BE] = "s32be",
        [PA_SAMPLE_S24LE] = "s24le",
        [PA_SAMPLE_S24BE] = "s24be",
        [PA_SAMPLE_S24_32LE] = "s24-32le",
        [PA_SAMPLE_S24_32BE] = "s24-32be",
    };

    return table[f];
}


char* pa_sample_spec_snprint(char *s,  size_t l, const pa_sample_spec *spec){
    log("pa_sample_spec_snprint: %p %zu %p  \n", s, l, spec);
    snprintf(s, l, ("%s %uch %uHz"), pa_sample_format_to_string(spec->format), spec->channels, spec->rate);
    log("Printing sample spec(pa_sample_spec_snprint): %s\n", s);
    return s;
}

pa_sample_spec* pa_stream_get_sample_spec(stream_t *s){
    log("pa_stream_get_sample_spec: giving smth\n");
    return &s->sample_spec;
}


size_t pa_frame_size(const pa_sample_spec *spec) {
    return size_table[spec->format] * spec->channels;
}



void pa_stream_set_write_callback(stream_t *s, pa_stream_request_cb_t cb, void *userdata){
    log("pa_stream_set_write_callback: Setting write callback=%p \n", cb);
    s->write_callback = cb;
    s->write_userdata = userdata;
}


void pa_stream_set_read_callback(stream_t *s, pa_stream_request_cb_t cb, void *userdata){
    log("pa_stream_set_read_callback: Setting read callback=%p\n", cb);
    s->read_callback = cb;
    s->read_userdata = userdata;
}

void pa_stream_set_state_callback(stream_t* s, pa_stream_notify_cb_t cb, void *userdata){
    log("pa_stream_set_state_callback: Setting stream state callback=%p\n", cb);
    s->notify_callback = cb;
    s->notify_userdata = userdata;
}

void pa_stream_set_underflow_callback(stream_t *s,	pa_stream_notify_cb_t cb, void *userdata){
    log("pa_stream_set_underflow_callback: Setting callback=%p\n", cb);
    s->underflow_callback = cb;
    s->underflow_userdata = userdata;
}



pa_stream_state_t pa_stream_get_state (int *p){
    log("pa_stream_get_state: reporting ready\n");
    return PA_STREAM_READY;
}


int* pa_stream_cork(stream_t *s, int b, pa_stream_success_cb_t cb, void *userdata){//pa_stream_success_cb_t cb
    log("pa_stream_cork: b=%d   callback=%p  userdata=%p  (on device=%s)\n", b, cb, userdata, s->name);
    s->corked = b;
    usleep(1500);
    cb(s, 1, userdata);
    return &operation;
}

static void *oss_thread_function(void *s1){
    stream_t* s = s1;
    char data[5120000];
    size_t n_data;
    while(s->running){
        if(s->read_callback){
            /* This just spams skype with requests to read data from the microphone (probably not a good idea but works) */
            s->read_callback(s, 31200, s->read_userdata);
            usleep(100000);
        }
        if(s->write_callback){
            n_data = why_buffer_read(s->buffer, data);
            while(s->corked){
                usleep(1000);
            }
            if(n_data&&s->running){
                if(s->write_callback) s->write_callback(s, n_data, s->write_userdata);
                int res = write(s->fd, data, n_data);
                log("wrote %d/%d bytes\n", res, n_data);
            }
            
        }
    }
    log("exiting oss thread\n");
}


int pa_stream_peek(stream_t *s, const void **data,	size_t *nbytes){
    static char g_data[10240];
    log("pa_stream_peek: reading from /dev/dsp\n");
    *nbytes = read(s->fd, g_data, 10240);
    *data = g_data;
    return 0;
}

int pa_stream_drop(stream_t *p){
    log("pa_stream_peek: nothing to do here\n");
    return 0;
}


int pa_stream_connect_playback (stream_t *s, const char *dev, const pa_buffer_attr *attr,	
                                int flags, const int *volume,	int *sync_stream){
    log("pa_stream_connect_playback: device_name=%s    attr=%p  sync_stream=%p\n", dev, attr, sync_stream);
    if(attr) s->buffer_attr = *attr;
    else{
        s->buffer_attr.maxlength = 1024000;
        s->buffer_attr.tlength = 51200;
        s->buffer_attr.prebuf = 0;
        s->buffer_attr.minreq = 0;
        s->buffer_attr.fragsize = 51200;
    }
    s->buffer = why_buffer_new(1024000);
    
    log("State callback:\n");
    in_thread=1;
    s->notify_callback(s, s->notify_userdata);
    in_thread=0;
    log("Done state callback\n");
    const char* dsp = "/dev/dsp";
    if ((s->fd = open(dsp, O_RDWR)) == -1) {
		log("Error: failed to open %s\n", dsp);
	}
    
    int i, j;
#define SET(what, to) i = to; \
	j = ioctl(s->fd, what, &i); \
	if (j == -1) \
		log("Error: failed to set %s to %i\n", #what, i);

	SET(SNDCTL_DSP_CHANNELS, s->sample_spec.channels);
	SET(SNDCTL_DSP_SETFMT, AFMT_S16_NE);
	SET(SNDCTL_DSP_SPEED, s->sample_spec.rate);
    
    s->running=1;
    
    pthread_create(&s->thread, NULL, (void* )oss_thread_function, s);
    //pthread_detach(s->thread);
    
    return 0;
    
}

int pa_stream_connect_record(stream_t* s, const char *dev, const pa_buffer_attr *attr, int flags){
    log("pa_stream_connect_record: device_name=%s    attr=%p\n", dev, attr);
    log("#################################\n");
    //return -1;
    s->write_callback = NULL;
    pa_stream_connect_playback(s, dev, attr, flags, NULL, NULL);
    return 0;
}


int pa_stream_disconnect(stream_t* s){
    log("pa_stream_disconnect: disconnecting stream %s\n", s->name);
    s->running = 0;
    s->corked=0;
    pthread_join(s->thread, NULL);
    usleep(10000);
    log("Closing fd\n");
    close(s->fd);
    why_buffer_delete(s->buffer);
    return 0;
}

void pa_stream_unref(stream_t* s){
    log("pa_stream_unref: doing nothing(maybe free some memory?)\n");
    free(s);
}


int pa_stream_write(stream_t *s, const void *data, size_t nbytes, pa_free_cb_t free_cb,	int64_t offset,	pa_seek_mode_t seek){
    log("pa_stream_write: nbytes=%zu   free_cb=%p   offset=%lld seek_mode=%d \n", nbytes, free_cb, offset, seek);
    why_buffer_write(s->buffer, (char*)data, nbytes);
    return 0;
}

int* pa_stream_trigger(stream_t* s, pa_stream_success_cb_t cb, void *userdata){
    log("pa_stream_trigger: nothing to do\n");
    in_thread = 1;
    if(cb) cb(s, 1, userdata);
    in_thread = 0;
    return &operation;
}


const pa_buffer_attr* pa_stream_get_buffer_attr(stream_t *s){
    log("pa_stream_get_buffer_attr: returning buffer attributes\n");
    return &s->buffer_attr;
}


void pa_threaded_mainloop_signal(int *m, int wait_for_accept){
    log("pa_threaded_mainloop_signal: wait_for_accept=%d  Not doing anything here actually\n", wait_for_accept);
    return;
}

uint32_t pa_stream_get_device_index(stream_t *s){
    log("pa_stream_get_device_index: not implemented\n");
    return 0;
}

typedef void(* pa_context_success_cb_t)(int *c, int success, void *userdata);

int* pa_context_set_sink_volume_by_index(int *c, uint32_t idx, const int *volume, 
                                         pa_context_success_cb_t cb, void *userdata){
    log("pa_context_set_sink_volume_by_index: not doing anything\n");
    if(cb) cb(c, 1, userdata);
    return &operation;
}

int *pa_context_set_source_volume_by_index(int *c, uint32_t idx, 
                                           const int *volume, pa_context_success_cb_t cb, void *userdata){
    log("pa_context_set_source_volume_by_index: not doing anything  cb=%p\n", cb);
    if(cb) cb(c, 1, userdata);
    return &operation;
}


typedef enum pa_subscription_event_type pa_subscription_event_type_t;

typedef void(* pa_context_subscribe_cb_t)(int *c, pa_subscription_event_type_t t, uint32_t idx, void *userdata);

static pa_context_subscribe_cb_t subscribe_callback;

static void* subscribe_userdata;

void pa_context_set_subscribe_callback  (int *c, pa_context_subscribe_cb_t  cb, void *userdata){
    subscribe_userdata = userdata;
    subscribe_callback = cb;
}


typedef void(* pa_context_success_cb_t)(int *c, int success, void *userdata);

int* pa_context_subscribe(int *c, pa_subscription_mask_t m, pa_context_success_cb_t cb, void *userdata){
    log("pa_context_subscribe: subscribing mask=%0x   callback=%p   userdata=%p \n", m, cb, userdata);
 
}

int pa_context_connect (int * c, const char * server, int flags, pa_spawn_api *api){
    if(api!=NULL)
        log("Connecting context with server=%s and spawn function %p %p %p\n", server, api->prefork, api->postfork, api->atfork);
    else log("Connecting context with server=%s and no spawn functions\n", server);
    log("CALLBACK\n");
    in_thread = 1;
    state_callback(&context, state_userdata);
    in_thread = 0;
    log("RETURNED FROM CALLBACK\n");
    return 0;
}

void pa_context_unref(int *c){
    log("pa_context_unref: nothing to do here\n");
}


int pa_threaded_mainloop_in_thread(int *m){
    log("Reporting inthread status:%d\n", in_thread);
    return in_thread;
}


pa_context_state_t pa_context_get_state(int *c){
    return PA_CONTEXT_READY;
}


pa_operation_state_t pa_operation_get_state(int *o){
    log("pa_operation_get_state: reporting operation done\n");
    return PA_OPERATION_DONE;
}

void pa_operation_unref (int *o){
    log("pa_operation_unref: nothing to do\n");
}

void pa_init_i18n(void){
    log("pa_init_i18n: nothing to do\n");
}

/* The following functions don't seem to be used by skype. 
 * Nevertheless, skype does call the pa_threaded_mainloop_get_api function, 
 * so we keep it to be safe: */

static void* d_io_new(){
    log("io_new\n");
    return NULL;
}
static void d_io_enable(){
    log("io_enable\n");
}
static void d_io_free(){
    log("io_free\n");
}
static void d_io_set_destroy(){
    log("io_set_destroy\n");
}


static void* d_time_new(){
    log("time_new\n");
    return NULL;
}
static void d_time_restart(){
    log("time_restart\n");
}
static void d_time_free(){
    log("time_free\n");
}
static void d_time_set_destroy(){
    log("time_set_destroy\n");
}

static void* d_defer_new(){
    log("d_defer_new\n");
    return NULL;
}
static void d_defer_enable(){
    log("defer_enable\n");
}
static void d_defer_free(){
    log("defer_free\n");
}
static void d_defer_set_destroy(){
    log("defer_set_destroy\n");
}

static void d_quit(){
    log("quit\n");
}

static void* d_rtclock_time_new(){
    log("d_rtclock_time_new\n");
    return NULL;
}
static void d_rtclock_time_restart(){
    log("d_rtclock_time_restart\n");
}

pa_mainloop_api api;

pa_mainloop_api* pa_threaded_mainloop_get_api (int * m){
    api.userdata=NULL;
    
    api.io_new = d_io_new;
    api.io_enable = d_io_enable;
    api.io_set_destroy = d_io_set_destroy;

    api.time_new = d_time_new;
    api.time_restart = d_time_restart;
    api.time_free = d_time_free;
    api.time_set_destroy = d_time_set_destroy;

    api.defer_new = d_defer_new;
    api.defer_enable = d_defer_enable;
    api.defer_free = d_defer_free;
    api.defer_set_destroy = d_defer_set_destroy;
    
    api.quit = d_quit;

    api.rtclock_time_new = d_rtclock_time_new; 
    api.rtclock_time_restart = d_rtclock_time_restart; 

    log("pa_threaded_mainloop_get_api: Giving fake mainloop API %p\n", &api);

    return &api;
}

/* This is a complete list of pulseaudio symbols: */

#define NOT_IMPLEMENTED(f) int f(){ printf("NOT IMPLEMENTED:" #f  "\n"); };

NOT_IMPLEMENTED(pa_accept_cloexec)
NOT_IMPLEMENTED(pa_ascii_filter)
NOT_IMPLEMENTED(pa_ascii_valid)
NOT_IMPLEMENTED(pa_atod)
NOT_IMPLEMENTED(pa_atoi)
NOT_IMPLEMENTED(pa_atol)
NOT_IMPLEMENTED(pa_atou)
NOT_IMPLEMENTED(pa_aupdate_free)
NOT_IMPLEMENTED(pa_aupdate_new)
NOT_IMPLEMENTED(pa_aupdate_read_begin)
NOT_IMPLEMENTED(pa_aupdate_read_end)
NOT_IMPLEMENTED(pa_aupdate_write_begin)
NOT_IMPLEMENTED(pa_aupdate_write_end)
NOT_IMPLEMENTED(pa_aupdate_write_swap)
NOT_IMPLEMENTED(pa_authkey_load)
NOT_IMPLEMENTED(pa_authkey_load_auto)
NOT_IMPLEMENTED(pa_authkey_save)
NOT_IMPLEMENTED(pa_autospawn_lock_acquire)
NOT_IMPLEMENTED(pa_autospawn_lock_done)
NOT_IMPLEMENTED(pa_autospawn_lock_init)
NOT_IMPLEMENTED(pa_autospawn_lock_release)
NOT_IMPLEMENTED(pa_bitset_equals)
NOT_IMPLEMENTED(pa_bitset_get)
NOT_IMPLEMENTED(pa_bitset_set)
NOT_IMPLEMENTED(pa_bytes_per_second)
NOT_IMPLEMENTED(pa_bytes_snprint)
NOT_IMPLEMENTED(pa_bytes_to_usec)
NOT_IMPLEMENTED(pa_bytes_to_usec_round_up)
NOT_IMPLEMENTED(pa_channel_map_can_balance)
NOT_IMPLEMENTED(pa_channel_map_can_fade)
NOT_IMPLEMENTED(pa_channel_map_compatible)
NOT_IMPLEMENTED(pa_channel_map_equal)
NOT_IMPLEMENTED(pa_channel_map_has_position)
NOT_IMPLEMENTED(pa_channel_map_init)
NOT_IMPLEMENTED(pa_channel_map_init_auto)
NOT_IMPLEMENTED(pa_channel_map_init_extend)
/*NOT_IMPLEMENTED(pa_channel_map_init_mono)*/
/*NOT_IMPLEMENTED(pa_channel_map_init_stereo)*/
NOT_IMPLEMENTED(pa_channel_map_mask)
NOT_IMPLEMENTED(pa_channel_map_parse)
NOT_IMPLEMENTED(pa_channel_map_snprint)
NOT_IMPLEMENTED(pa_channel_map_superset)
NOT_IMPLEMENTED(pa_channel_map_to_name)
NOT_IMPLEMENTED(pa_channel_map_to_pretty_name)
NOT_IMPLEMENTED(pa_channel_map_valid)
NOT_IMPLEMENTED(pa_channel_position_from_string)
NOT_IMPLEMENTED(pa_channel_position_to_pretty_string)
NOT_IMPLEMENTED(pa_channel_position_to_string)
NOT_IMPLEMENTED(pa_channels_valid)
NOT_IMPLEMENTED(pa_check_in_group)
NOT_IMPLEMENTED(pa_check_signal_is_blocked)
NOT_IMPLEMENTED(pa_client_conf_env)
NOT_IMPLEMENTED(pa_client_conf_free)
NOT_IMPLEMENTED(pa_client_conf_from_x11)
NOT_IMPLEMENTED(pa_client_conf_load)
NOT_IMPLEMENTED(pa_client_conf_load_cookie_from_file)
NOT_IMPLEMENTED(pa_client_conf_load_cookie_from_hex)
NOT_IMPLEMENTED(pa_client_conf_new)
NOT_IMPLEMENTED(pa_client_conf_set_cookie)
NOT_IMPLEMENTED(pa_close)
NOT_IMPLEMENTED(pa_close_all)
NOT_IMPLEMENTED(pa_close_allv)
NOT_IMPLEMENTED(pa_close_pipe)
NOT_IMPLEMENTED(pa_cond_free)
NOT_IMPLEMENTED(pa_cond_new)
NOT_IMPLEMENTED(pa_cond_signal)
NOT_IMPLEMENTED(pa_cond_wait)
NOT_IMPLEMENTED(pa_config_parse)
NOT_IMPLEMENTED(pa_config_parse_bool)
NOT_IMPLEMENTED(pa_config_parse_int)
NOT_IMPLEMENTED(pa_config_parse_not_bool)
NOT_IMPLEMENTED(pa_config_parse_size)
NOT_IMPLEMENTED(pa_config_parse_string)
NOT_IMPLEMENTED(pa_config_parse_unsigned)
NOT_IMPLEMENTED(pa_context_add_autoload)
/*NOT_IMPLEMENTED(pa_context_connect)*/
/*NOT_IMPLEMENTED(pa_context_disconnect)*/
/*NOT_IMPLEMENTED(pa_context_drain)*/
NOT_IMPLEMENTED(pa_context_errno)
NOT_IMPLEMENTED(pa_context_exit_daemon)
NOT_IMPLEMENTED(pa_context_get_autoload_info_by_index)
NOT_IMPLEMENTED(pa_context_get_autoload_info_by_name)
NOT_IMPLEMENTED(pa_context_get_autoload_info_list)
NOT_IMPLEMENTED(pa_context_get_card_info_by_index)
NOT_IMPLEMENTED(pa_context_get_card_info_by_name)
NOT_IMPLEMENTED(pa_context_get_card_info_list)
NOT_IMPLEMENTED(pa_context_get_client_info)
NOT_IMPLEMENTED(pa_context_get_client_info_list)
NOT_IMPLEMENTED(pa_context_get_index)
NOT_IMPLEMENTED(pa_context_get_module_info)
NOT_IMPLEMENTED(pa_context_get_module_info_list)
NOT_IMPLEMENTED(pa_context_get_protocol_version)
NOT_IMPLEMENTED(pa_context_get_sample_info_by_index)
NOT_IMPLEMENTED(pa_context_get_sample_info_by_name)
NOT_IMPLEMENTED(pa_context_get_sample_info_list)
NOT_IMPLEMENTED(pa_context_get_server)
NOT_IMPLEMENTED(pa_context_get_server_info)
NOT_IMPLEMENTED(pa_context_get_server_protocol_version)
NOT_IMPLEMENTED(pa_context_get_sink_info_by_index)
NOT_IMPLEMENTED(pa_context_get_sink_info_by_name)
NOT_IMPLEMENTED(pa_context_get_sink_info_list)
NOT_IMPLEMENTED(pa_context_get_sink_input_info)
NOT_IMPLEMENTED(pa_context_get_sink_input_info_list)
NOT_IMPLEMENTED(pa_context_get_source_info_by_index)
NOT_IMPLEMENTED(pa_context_get_source_info_by_name)
NOT_IMPLEMENTED(pa_context_get_source_info_list)
NOT_IMPLEMENTED(pa_context_get_source_output_info)
NOT_IMPLEMENTED(pa_context_get_source_output_info_list)
/*NOT_IMPLEMENTED(pa_context_get_state)*/
NOT_IMPLEMENTED(pa_context_get_tile_size)
NOT_IMPLEMENTED(pa_context_is_local)
NOT_IMPLEMENTED(pa_context_is_pending)
NOT_IMPLEMENTED(pa_context_kill_client)
NOT_IMPLEMENTED(pa_context_kill_sink_input)
NOT_IMPLEMENTED(pa_context_kill_source_output)
NOT_IMPLEMENTED(pa_context_load_cookie_from_file)
NOT_IMPLEMENTED(pa_context_load_module)
NOT_IMPLEMENTED(pa_context_move_sink_input_by_index)
NOT_IMPLEMENTED(pa_context_move_sink_input_by_name)
NOT_IMPLEMENTED(pa_context_move_source_output_by_index)
NOT_IMPLEMENTED(pa_context_move_source_output_by_name)
/*NOT_IMPLEMENTED(pa_context_new)*/
NOT_IMPLEMENTED(pa_context_new_with_proplist)
NOT_IMPLEMENTED(pa_context_play_sample)
NOT_IMPLEMENTED(pa_context_play_sample_with_proplist)
NOT_IMPLEMENTED(pa_context_proplist_remove)
NOT_IMPLEMENTED(pa_context_proplist_update)
NOT_IMPLEMENTED(pa_context_ref)
NOT_IMPLEMENTED(pa_context_remove_autoload_by_index)
NOT_IMPLEMENTED(pa_context_remove_autoload_by_name)
NOT_IMPLEMENTED(pa_context_remove_sample)
NOT_IMPLEMENTED(pa_context_rttime_new)
NOT_IMPLEMENTED(pa_context_rttime_restart)
NOT_IMPLEMENTED(pa_context_set_card_profile_by_index)
NOT_IMPLEMENTED(pa_context_set_card_profile_by_name)
NOT_IMPLEMENTED(pa_context_set_default_sink)
NOT_IMPLEMENTED(pa_context_set_default_source)
NOT_IMPLEMENTED(pa_context_set_event_callback)
NOT_IMPLEMENTED(pa_context_set_name)
NOT_IMPLEMENTED(pa_context_set_port_latency_offset)
NOT_IMPLEMENTED(pa_context_set_sink_input_mute)
NOT_IMPLEMENTED(pa_context_set_sink_input_volume)
NOT_IMPLEMENTED(pa_context_set_sink_mute_by_index)
NOT_IMPLEMENTED(pa_context_set_sink_mute_by_name)
NOT_IMPLEMENTED(pa_context_set_sink_port_by_index)
NOT_IMPLEMENTED(pa_context_set_sink_port_by_name)
/*NOT_IMPLEMENTED(pa_context_set_sink_volume_by_index)*/
NOT_IMPLEMENTED(pa_context_set_sink_volume_by_name)
NOT_IMPLEMENTED(pa_context_set_source_mute_by_index)
NOT_IMPLEMENTED(pa_context_set_source_mute_by_name)
NOT_IMPLEMENTED(pa_context_set_source_output_mute)
NOT_IMPLEMENTED(pa_context_set_source_output_volume)
NOT_IMPLEMENTED(pa_context_set_source_port_by_index)
NOT_IMPLEMENTED(pa_context_set_source_port_by_name)
/*NOT_IMPLEMENTED(pa_context_set_source_volume_by_index)*/
NOT_IMPLEMENTED(pa_context_set_source_volume_by_name)
/*NOT_IMPLEMENTED(pa_context_set_state_callback)*/
/*NOT_IMPLEMENTED(pa_context_set_subscribe_callback)*/
NOT_IMPLEMENTED(pa_context_stat)
/*NOT_IMPLEMENTED(pa_context_subscribe)*/
NOT_IMPLEMENTED(pa_context_suspend_sink_by_index)
NOT_IMPLEMENTED(pa_context_suspend_sink_by_name)
NOT_IMPLEMENTED(pa_context_suspend_source_by_index)
NOT_IMPLEMENTED(pa_context_suspend_source_by_name)
NOT_IMPLEMENTED(pa_context_unload_module)
/*NOT_IMPLEMENTED(pa_context_unref)*/
NOT_IMPLEMENTED(pa_convert_size)
NOT_IMPLEMENTED(pa_cstrerror)
NOT_IMPLEMENTED(pa_cvolume_avg)
NOT_IMPLEMENTED(pa_cvolume_avg_mask)
NOT_IMPLEMENTED(pa_cvolume_channels_equal_to)
NOT_IMPLEMENTED(pa_cvolume_compatible)
NOT_IMPLEMENTED(pa_cvolume_compatible_with_channel_map)
NOT_IMPLEMENTED(pa_cvolume_dec)
NOT_IMPLEMENTED(pa_cvolume_equal)
NOT_IMPLEMENTED(pa_cvolume_get_balance)
NOT_IMPLEMENTED(pa_cvolume_get_fade)
NOT_IMPLEMENTED(pa_cvolume_get_position)
NOT_IMPLEMENTED(pa_cvolume_inc)
NOT_IMPLEMENTED(pa_cvolume_inc_clamp)
NOT_IMPLEMENTED(pa_cvolume_init)
NOT_IMPLEMENTED(pa_cvolume_max)
NOT_IMPLEMENTED(pa_cvolume_max_mask)
NOT_IMPLEMENTED(pa_cvolume_merge)
NOT_IMPLEMENTED(pa_cvolume_min)
NOT_IMPLEMENTED(pa_cvolume_min_mask)
NOT_IMPLEMENTED(pa_cvolume_remap)
NOT_IMPLEMENTED(pa_cvolume_scale)
NOT_IMPLEMENTED(pa_cvolume_scale_mask)
/*NOT_IMPLEMENTED(pa_cvolume_set)*/
NOT_IMPLEMENTED(pa_cvolume_set_balance)
NOT_IMPLEMENTED(pa_cvolume_set_fade)
NOT_IMPLEMENTED(pa_cvolume_set_position)
NOT_IMPLEMENTED(pa_cvolume_snprint)
NOT_IMPLEMENTED(pa_cvolume_snprint_verbose)
NOT_IMPLEMENTED(pa_cvolume_valid)
NOT_IMPLEMENTED(pa_deinterleave)
NOT_IMPLEMENTED(pa_detect_fork)
NOT_IMPLEMENTED(pa_disable_sigpipe)
NOT_IMPLEMENTED(pa_dynarray_append)
NOT_IMPLEMENTED(pa_dynarray_free)
NOT_IMPLEMENTED(pa_dynarray_get)
NOT_IMPLEMENTED(pa_dynarray_new)
NOT_IMPLEMENTED(pa_dynarray_size)
NOT_IMPLEMENTED(pa_dynarray_steal_last)
NOT_IMPLEMENTED(pa_encoding_from_string)
NOT_IMPLEMENTED(pa_encoding_to_string)
NOT_IMPLEMENTED(pa_endswith)
NOT_IMPLEMENTED(pa_escape)
NOT_IMPLEMENTED(pa_ext_device_manager_delete)
NOT_IMPLEMENTED(pa_ext_device_manager_enable_role_device_priority_routing)
NOT_IMPLEMENTED(pa_ext_device_manager_read)
NOT_IMPLEMENTED(pa_ext_device_manager_reorder_devices_for_role)
NOT_IMPLEMENTED(pa_ext_device_manager_set_device_description)
NOT_IMPLEMENTED(pa_ext_device_manager_set_subscribe_cb)
NOT_IMPLEMENTED(pa_ext_device_manager_subscribe)
NOT_IMPLEMENTED(pa_ext_device_manager_test)
NOT_IMPLEMENTED(pa_ext_device_restore_read_formats)
NOT_IMPLEMENTED(pa_ext_device_restore_read_formats_all)
NOT_IMPLEMENTED(pa_ext_device_restore_save_formats)
NOT_IMPLEMENTED(pa_ext_device_restore_set_subscribe_cb)
NOT_IMPLEMENTED(pa_ext_device_restore_subscribe)
NOT_IMPLEMENTED(pa_ext_device_restore_test)
NOT_IMPLEMENTED(pa_ext_stream_restore_delete)
NOT_IMPLEMENTED(pa_ext_stream_restore_read)
NOT_IMPLEMENTED(pa_ext_stream_restore_set_subscribe_cb)
NOT_IMPLEMENTED(pa_ext_stream_restore_subscribe)
NOT_IMPLEMENTED(pa_ext_stream_restore_test)
NOT_IMPLEMENTED(pa_ext_stream_restore_write)
NOT_IMPLEMENTED(pa_find_config_file)
NOT_IMPLEMENTED(pa_flist_free)
NOT_IMPLEMENTED(pa_flist_new)
NOT_IMPLEMENTED(pa_flist_new_with_name)
NOT_IMPLEMENTED(pa_flist_pop)
NOT_IMPLEMENTED(pa_flist_push)
NOT_IMPLEMENTED(pa_fopen_cloexec)
NOT_IMPLEMENTED(pa_format_info_copy)
NOT_IMPLEMENTED(pa_format_info_free)
NOT_IMPLEMENTED(pa_format_info_free_string_array)
NOT_IMPLEMENTED(pa_format_info_from_sample_spec)
NOT_IMPLEMENTED(pa_format_info_from_sample_spec2)
NOT_IMPLEMENTED(pa_format_info_from_string)
NOT_IMPLEMENTED(pa_format_info_get_channel_map)
NOT_IMPLEMENTED(pa_format_info_get_channels)
NOT_IMPLEMENTED(pa_format_info_get_prop_int)
NOT_IMPLEMENTED(pa_format_info_get_prop_int_array)
NOT_IMPLEMENTED(pa_format_info_get_prop_int_range)
NOT_IMPLEMENTED(pa_format_info_get_prop_string)
NOT_IMPLEMENTED(pa_format_info_get_prop_string_array)
NOT_IMPLEMENTED(pa_format_info_get_prop_type)
NOT_IMPLEMENTED(pa_format_info_get_rate)
NOT_IMPLEMENTED(pa_format_info_get_sample_format)
NOT_IMPLEMENTED(pa_format_info_is_compatible)
NOT_IMPLEMENTED(pa_format_info_is_pcm)
NOT_IMPLEMENTED(pa_format_info_new)
NOT_IMPLEMENTED(pa_format_info_set_channel_map)
NOT_IMPLEMENTED(pa_format_info_set_channels)
NOT_IMPLEMENTED(pa_format_info_set_prop_int)
NOT_IMPLEMENTED(pa_format_info_set_prop_int_array)
NOT_IMPLEMENTED(pa_format_info_set_prop_int_range)
NOT_IMPLEMENTED(pa_format_info_set_prop_string)
NOT_IMPLEMENTED(pa_format_info_set_prop_string_array)
NOT_IMPLEMENTED(pa_format_info_set_rate)
NOT_IMPLEMENTED(pa_format_info_set_sample_format)
NOT_IMPLEMENTED(pa_format_info_snprint)
NOT_IMPLEMENTED(pa_format_info_to_sample_spec)
NOT_IMPLEMENTED(pa_format_info_to_sample_spec2)
NOT_IMPLEMENTED(pa_format_info_to_sample_spec_fake)
NOT_IMPLEMENTED(pa_format_info_valid)
NOT_IMPLEMENTED(pa_frame_align)
NOT_IMPLEMENTED(pa_frame_aligned)
/*NOT_IMPLEMENTED(pa_frame_size)*/
NOT_IMPLEMENTED(pa_gcd)
NOT_IMPLEMENTED(pa_get_binary_name)
NOT_IMPLEMENTED(pa_get_binary_name_malloc)
NOT_IMPLEMENTED(pa_get_fqdn)
NOT_IMPLEMENTED(pa_get_gid_of_group)
NOT_IMPLEMENTED(pa_get_home_dir)
NOT_IMPLEMENTED(pa_get_home_dir_malloc)
NOT_IMPLEMENTED(pa_get_host_name)
NOT_IMPLEMENTED(pa_get_host_name_malloc)
/*NOT_IMPLEMENTED(pa_get_library_version)*/
NOT_IMPLEMENTED(pa_get_runtime_dir)
NOT_IMPLEMENTED(pa_get_state_dir)
NOT_IMPLEMENTED(pa_get_temp_dir)
NOT_IMPLEMENTED(pa_get_user_name)
NOT_IMPLEMENTED(pa_get_user_name_malloc)
NOT_IMPLEMENTED(pa_get_volume_func)
NOT_IMPLEMENTED(pa_getcwd)
NOT_IMPLEMENTED(pa_getgrgid_free)
NOT_IMPLEMENTED(pa_getgrgid_malloc)
NOT_IMPLEMENTED(pa_getgrnam_free)
NOT_IMPLEMENTED(pa_getgrnam_malloc)
NOT_IMPLEMENTED(pa_getpwnam_free)
NOT_IMPLEMENTED(pa_getpwnam_malloc)
NOT_IMPLEMENTED(pa_getpwuid_free)
NOT_IMPLEMENTED(pa_getpwuid_malloc)
NOT_IMPLEMENTED(pa_gettimeofday)
NOT_IMPLEMENTED(pa_hashmap_first)
NOT_IMPLEMENTED(pa_hashmap_free)
NOT_IMPLEMENTED(pa_hashmap_get)
NOT_IMPLEMENTED(pa_hashmap_isempty)
NOT_IMPLEMENTED(pa_hashmap_iterate)
NOT_IMPLEMENTED(pa_hashmap_iterate_backwards)
NOT_IMPLEMENTED(pa_hashmap_last)
NOT_IMPLEMENTED(pa_hashmap_new)
NOT_IMPLEMENTED(pa_hashmap_new_full)
NOT_IMPLEMENTED(pa_hashmap_put)
NOT_IMPLEMENTED(pa_hashmap_remove)
NOT_IMPLEMENTED(pa_hashmap_remove_all)
NOT_IMPLEMENTED(pa_hashmap_size)
NOT_IMPLEMENTED(pa_hashmap_steal_first)
NOT_IMPLEMENTED(pa_hexstr)
NOT_IMPLEMENTED(pa_idxset_copy)
NOT_IMPLEMENTED(pa_idxset_first)
NOT_IMPLEMENTED(pa_idxset_free)
NOT_IMPLEMENTED(pa_idxset_get_by_data)
NOT_IMPLEMENTED(pa_idxset_get_by_index)
NOT_IMPLEMENTED(pa_idxset_isempty)
NOT_IMPLEMENTED(pa_idxset_iterate)
NOT_IMPLEMENTED(pa_idxset_new)
NOT_IMPLEMENTED(pa_idxset_next)
NOT_IMPLEMENTED(pa_idxset_put)
NOT_IMPLEMENTED(pa_idxset_remove_all)
NOT_IMPLEMENTED(pa_idxset_remove_by_data)
NOT_IMPLEMENTED(pa_idxset_remove_by_index)
NOT_IMPLEMENTED(pa_idxset_rrobin)
NOT_IMPLEMENTED(pa_idxset_size)
NOT_IMPLEMENTED(pa_idxset_steal_first)
NOT_IMPLEMENTED(pa_idxset_string_compare_func)
NOT_IMPLEMENTED(pa_idxset_string_hash_func)
NOT_IMPLEMENTED(pa_idxset_trivial_compare_func)
NOT_IMPLEMENTED(pa_idxset_trivial_hash_func)
NOT_IMPLEMENTED(pa_in_system_mode)
/*NOT_IMPLEMENTED(pa_init_i18n)*/
NOT_IMPLEMENTED(pa_init_proplist)
NOT_IMPLEMENTED(pa_interleave)
NOT_IMPLEMENTED(pa_iochannel_creds_enable)
NOT_IMPLEMENTED(pa_iochannel_creds_supported)
NOT_IMPLEMENTED(pa_iochannel_free)
NOT_IMPLEMENTED(pa_iochannel_get_mainloop_api)
NOT_IMPLEMENTED(pa_iochannel_get_recv_fd)
NOT_IMPLEMENTED(pa_iochannel_get_send_fd)
NOT_IMPLEMENTED(pa_iochannel_is_hungup)
NOT_IMPLEMENTED(pa_iochannel_is_readable)
NOT_IMPLEMENTED(pa_iochannel_is_writable)
NOT_IMPLEMENTED(pa_iochannel_new)
NOT_IMPLEMENTED(pa_iochannel_read)
NOT_IMPLEMENTED(pa_iochannel_read_with_creds)
NOT_IMPLEMENTED(pa_iochannel_set_callback)
NOT_IMPLEMENTED(pa_iochannel_set_noclose)
NOT_IMPLEMENTED(pa_iochannel_socket_is_local)
NOT_IMPLEMENTED(pa_iochannel_socket_peer_to_string)
NOT_IMPLEMENTED(pa_iochannel_socket_set_rcvbuf)
NOT_IMPLEMENTED(pa_iochannel_socket_set_sndbuf)
NOT_IMPLEMENTED(pa_iochannel_write)
NOT_IMPLEMENTED(pa_iochannel_write_with_creds)
NOT_IMPLEMENTED(pa_ioline_close)
NOT_IMPLEMENTED(pa_ioline_defer_close)
NOT_IMPLEMENTED(pa_ioline_detach_iochannel)
NOT_IMPLEMENTED(pa_ioline_is_drained)
NOT_IMPLEMENTED(pa_ioline_new)
NOT_IMPLEMENTED(pa_ioline_printf)
NOT_IMPLEMENTED(pa_ioline_puts)
NOT_IMPLEMENTED(pa_ioline_ref)
NOT_IMPLEMENTED(pa_ioline_set_callback)
NOT_IMPLEMENTED(pa_ioline_set_drain_callback)
NOT_IMPLEMENTED(pa_ioline_unref)
NOT_IMPLEMENTED(pa_ip_acl_check)
NOT_IMPLEMENTED(pa_ip_acl_free)
NOT_IMPLEMENTED(pa_ip_acl_new)
NOT_IMPLEMENTED(pa_is_fd_nonblock)
NOT_IMPLEMENTED(pa_is_ip_address)
NOT_IMPLEMENTED(pa_is_path_absolute)
NOT_IMPLEMENTED(pa_locale_to_utf8)
NOT_IMPLEMENTED(pa_lock_fd)
NOT_IMPLEMENTED(pa_lock_lockfile)
NOT_IMPLEMENTED(pa_log_level)
NOT_IMPLEMENTED(pa_log_level_meta)
NOT_IMPLEMENTED(pa_log_levelv)
NOT_IMPLEMENTED(pa_log_levelv_meta)
NOT_IMPLEMENTED(pa_log_parse_target)
NOT_IMPLEMENTED(pa_log_ratelimit)
NOT_IMPLEMENTED(pa_log_set_flags)
NOT_IMPLEMENTED(pa_log_set_ident)
NOT_IMPLEMENTED(pa_log_set_level)
NOT_IMPLEMENTED(pa_log_set_show_backtrace)
NOT_IMPLEMENTED(pa_log_set_skip_backtrace)
NOT_IMPLEMENTED(pa_log_set_target)
NOT_IMPLEMENTED(pa_log_target_free)
NOT_IMPLEMENTED(pa_log_target_new)
NOT_IMPLEMENTED(pa_log_target_to_string)
NOT_IMPLEMENTED(pa_loop_read)
NOT_IMPLEMENTED(pa_loop_write)
NOT_IMPLEMENTED(pa_machine_id)
NOT_IMPLEMENTED(pa_mainloop_api_once)
NOT_IMPLEMENTED(pa_mainloop_dispatch)
NOT_IMPLEMENTED(pa_mainloop_free)
NOT_IMPLEMENTED(pa_mainloop_get_api)
NOT_IMPLEMENTED(pa_mainloop_get_retval)
NOT_IMPLEMENTED(pa_mainloop_iterate)
NOT_IMPLEMENTED(pa_mainloop_new)
NOT_IMPLEMENTED(pa_mainloop_poll)
NOT_IMPLEMENTED(pa_mainloop_prepare)
NOT_IMPLEMENTED(pa_mainloop_quit)
NOT_IMPLEMENTED(pa_mainloop_run)
NOT_IMPLEMENTED(pa_mainloop_set_poll_func)
NOT_IMPLEMENTED(pa_mainloop_wakeup)
NOT_IMPLEMENTED(pa_make_fd_block)
NOT_IMPLEMENTED(pa_make_fd_cloexec)
NOT_IMPLEMENTED(pa_make_fd_nonblock)
NOT_IMPLEMENTED(pa_make_path_absolute)
NOT_IMPLEMENTED(pa_make_realtime)
NOT_IMPLEMENTED(pa_make_secure_dir)
NOT_IMPLEMENTED(pa_make_secure_parent_dir)
NOT_IMPLEMENTED(pa_make_socket_low_delay)
NOT_IMPLEMENTED(pa_make_tcp_socket_low_delay)
NOT_IMPLEMENTED(pa_make_udp_socket_low_delay)
NOT_IMPLEMENTED(pa_match)
NOT_IMPLEMENTED(pa_maybe_prefix_path)
NOT_IMPLEMENTED(pa_mcalign_csize)
NOT_IMPLEMENTED(pa_mcalign_flush)
NOT_IMPLEMENTED(pa_mcalign_free)
NOT_IMPLEMENTED(pa_mcalign_new)
NOT_IMPLEMENTED(pa_mcalign_pop)
NOT_IMPLEMENTED(pa_mcalign_push)
NOT_IMPLEMENTED(pa_memblock_acquire)
NOT_IMPLEMENTED(pa_memblock_acquire_chunk)
NOT_IMPLEMENTED(pa_memblock_get_length)
NOT_IMPLEMENTED(pa_memblock_get_pool)
NOT_IMPLEMENTED(pa_memblock_is_read_only)
NOT_IMPLEMENTED(pa_memblock_is_silence)
NOT_IMPLEMENTED(pa_memblock_new)
NOT_IMPLEMENTED(pa_memblock_new_fixed)
NOT_IMPLEMENTED(pa_memblock_new_pool)
NOT_IMPLEMENTED(pa_memblock_new_user)
NOT_IMPLEMENTED(pa_memblock_ref)
NOT_IMPLEMENTED(pa_memblock_ref_is_one)
NOT_IMPLEMENTED(pa_memblock_release)
NOT_IMPLEMENTED(pa_memblock_set_is_silence)
NOT_IMPLEMENTED(pa_memblock_unref)
NOT_IMPLEMENTED(pa_memblock_unref_fixed)
NOT_IMPLEMENTED(pa_memblock_will_need)
NOT_IMPLEMENTED(pa_memblockq_apply_attr)
NOT_IMPLEMENTED(pa_memblockq_drop)
NOT_IMPLEMENTED(pa_memblockq_flush_read)
NOT_IMPLEMENTED(pa_memblockq_flush_write)
NOT_IMPLEMENTED(pa_memblockq_free)
NOT_IMPLEMENTED(pa_memblockq_get_attr)
NOT_IMPLEMENTED(pa_memblockq_get_base)
NOT_IMPLEMENTED(pa_memblockq_get_length)
NOT_IMPLEMENTED(pa_memblockq_get_maxlength)
NOT_IMPLEMENTED(pa_memblockq_get_maxrewind)
NOT_IMPLEMENTED(pa_memblockq_get_minreq)
NOT_IMPLEMENTED(pa_memblockq_get_nblocks)
NOT_IMPLEMENTED(pa_memblockq_get_prebuf)
NOT_IMPLEMENTED(pa_memblockq_get_read_index)
NOT_IMPLEMENTED(pa_memblockq_get_tlength)
NOT_IMPLEMENTED(pa_memblockq_get_write_index)
NOT_IMPLEMENTED(pa_memblockq_is_empty)
NOT_IMPLEMENTED(pa_memblockq_is_readable)
NOT_IMPLEMENTED(pa_memblockq_missing)
NOT_IMPLEMENTED(pa_memblockq_new)
NOT_IMPLEMENTED(pa_memblockq_peek)
NOT_IMPLEMENTED(pa_memblockq_peek_fixed_size)
NOT_IMPLEMENTED(pa_memblockq_pop_missing)
NOT_IMPLEMENTED(pa_memblockq_prebuf_active)
NOT_IMPLEMENTED(pa_memblockq_prebuf_disable)
NOT_IMPLEMENTED(pa_memblockq_prebuf_force)
NOT_IMPLEMENTED(pa_memblockq_push)
NOT_IMPLEMENTED(pa_memblockq_push_align)
NOT_IMPLEMENTED(pa_memblockq_rewind)
NOT_IMPLEMENTED(pa_memblockq_seek)
NOT_IMPLEMENTED(pa_memblockq_set_maxlength)
NOT_IMPLEMENTED(pa_memblockq_set_maxrewind)
NOT_IMPLEMENTED(pa_memblockq_set_minreq)
NOT_IMPLEMENTED(pa_memblockq_set_prebuf)
NOT_IMPLEMENTED(pa_memblockq_set_silence)
NOT_IMPLEMENTED(pa_memblockq_set_tlength)
NOT_IMPLEMENTED(pa_memblockq_silence)
NOT_IMPLEMENTED(pa_memblockq_splice)
NOT_IMPLEMENTED(pa_memblockq_willneed)
NOT_IMPLEMENTED(pa_memchunk_dump_to_file)
NOT_IMPLEMENTED(pa_memchunk_isset)
NOT_IMPLEMENTED(pa_memchunk_make_writable)
NOT_IMPLEMENTED(pa_memchunk_memcpy)
NOT_IMPLEMENTED(pa_memchunk_reset)
NOT_IMPLEMENTED(pa_memchunk_sine)
NOT_IMPLEMENTED(pa_memchunk_will_need)
NOT_IMPLEMENTED(pa_memexport_free)
NOT_IMPLEMENTED(pa_memexport_new)
NOT_IMPLEMENTED(pa_memexport_process_release)
NOT_IMPLEMENTED(pa_memexport_put)
NOT_IMPLEMENTED(pa_memimport_free)
NOT_IMPLEMENTED(pa_memimport_get)
NOT_IMPLEMENTED(pa_memimport_new)
NOT_IMPLEMENTED(pa_memimport_process_revoke)
NOT_IMPLEMENTED(pa_mempool_block_size_max)
NOT_IMPLEMENTED(pa_mempool_free)
NOT_IMPLEMENTED(pa_mempool_get_shm_id)
NOT_IMPLEMENTED(pa_mempool_get_stat)
NOT_IMPLEMENTED(pa_mempool_is_shared)
NOT_IMPLEMENTED(pa_mempool_new)
NOT_IMPLEMENTED(pa_mempool_vacuum)
NOT_IMPLEMENTED(pa_memtrap_add)
NOT_IMPLEMENTED(pa_memtrap_install)
NOT_IMPLEMENTED(pa_memtrap_is_good)
NOT_IMPLEMENTED(pa_memtrap_remove)
NOT_IMPLEMENTED(pa_memtrap_update)
NOT_IMPLEMENTED(pa_msleep)
NOT_IMPLEMENTED(pa_mutex_free)
NOT_IMPLEMENTED(pa_mutex_lock)
NOT_IMPLEMENTED(pa_mutex_new)
NOT_IMPLEMENTED(pa_mutex_try_lock)
NOT_IMPLEMENTED(pa_mutex_unlock)
NOT_IMPLEMENTED(pa_ncpus)
NOT_IMPLEMENTED(pa_nullify_stdfds)
NOT_IMPLEMENTED(pa_once_begin)
NOT_IMPLEMENTED(pa_once_end)
NOT_IMPLEMENTED(pa_open_cloexec)
NOT_IMPLEMENTED(pa_open_config_file)
NOT_IMPLEMENTED(pa_operation_cancel)
/*NOT_IMPLEMENTED(pa_operation_get_state)*/
NOT_IMPLEMENTED(pa_operation_ref)
NOT_IMPLEMENTED(pa_operation_set_state_callback)
/*NOT_IMPLEMENTED(pa_operation_unref)*/
NOT_IMPLEMENTED(pa_own_uid_in_group)
NOT_IMPLEMENTED(pa_packet_new)
NOT_IMPLEMENTED(pa_packet_new_dynamic)
NOT_IMPLEMENTED(pa_packet_ref)
NOT_IMPLEMENTED(pa_packet_unref)
NOT_IMPLEMENTED(pa_parent_dir)
NOT_IMPLEMENTED(pa_parse_address)
NOT_IMPLEMENTED(pa_parse_boolean)
NOT_IMPLEMENTED(pa_parse_sample_format)
NOT_IMPLEMENTED(pa_parse_volume)
NOT_IMPLEMENTED(pa_parsehex)
NOT_IMPLEMENTED(pa_path_get_filename)
NOT_IMPLEMENTED(pa_pdispatch_creds)
NOT_IMPLEMENTED(pa_pdispatch_is_pending)
NOT_IMPLEMENTED(pa_pdispatch_new)
NOT_IMPLEMENTED(pa_pdispatch_ref)
NOT_IMPLEMENTED(pa_pdispatch_register_reply)
NOT_IMPLEMENTED(pa_pdispatch_run)
NOT_IMPLEMENTED(pa_pdispatch_set_drain_callback)
NOT_IMPLEMENTED(pa_pdispatch_unref)
NOT_IMPLEMENTED(pa_pdispatch_unregister_reply)
NOT_IMPLEMENTED(pa_pid_file_check_running)
NOT_IMPLEMENTED(pa_pid_file_create)
NOT_IMPLEMENTED(pa_pid_file_kill)
NOT_IMPLEMENTED(pa_pid_file_remove)
NOT_IMPLEMENTED(pa_pipe_buf)
NOT_IMPLEMENTED(pa_pipe_cloexec)
NOT_IMPLEMENTED(pa_proplist_clear)
NOT_IMPLEMENTED(pa_proplist_contains)
NOT_IMPLEMENTED(pa_proplist_copy)
NOT_IMPLEMENTED(pa_proplist_equal)
NOT_IMPLEMENTED(pa_proplist_free)
NOT_IMPLEMENTED(pa_proplist_from_string)
NOT_IMPLEMENTED(pa_proplist_get)
NOT_IMPLEMENTED(pa_proplist_get_stream_group)
NOT_IMPLEMENTED(pa_proplist_gets)
NOT_IMPLEMENTED(pa_proplist_isempty)
NOT_IMPLEMENTED(pa_proplist_iterate)
NOT_IMPLEMENTED(pa_proplist_key_valid)
NOT_IMPLEMENTED(pa_proplist_new)
NOT_IMPLEMENTED(pa_proplist_set)
NOT_IMPLEMENTED(pa_proplist_setf)
NOT_IMPLEMENTED(pa_proplist_setp)
NOT_IMPLEMENTED(pa_proplist_sets)
NOT_IMPLEMENTED(pa_proplist_size)
NOT_IMPLEMENTED(pa_proplist_to_string)
NOT_IMPLEMENTED(pa_proplist_to_string_sep)
NOT_IMPLEMENTED(pa_proplist_unset)
NOT_IMPLEMENTED(pa_proplist_unset_many)
NOT_IMPLEMENTED(pa_proplist_update)
NOT_IMPLEMENTED(pa_pstream_enable_shm)
NOT_IMPLEMENTED(pa_pstream_get_shm)
NOT_IMPLEMENTED(pa_pstream_is_pending)
NOT_IMPLEMENTED(pa_pstream_new)
NOT_IMPLEMENTED(pa_pstream_ref)
NOT_IMPLEMENTED(pa_pstream_send_error)
NOT_IMPLEMENTED(pa_pstream_send_memblock)
NOT_IMPLEMENTED(pa_pstream_send_packet)
NOT_IMPLEMENTED(pa_pstream_send_release)
NOT_IMPLEMENTED(pa_pstream_send_revoke)
NOT_IMPLEMENTED(pa_pstream_send_simple_ack)
NOT_IMPLEMENTED(pa_pstream_send_tagstruct_with_creds)
NOT_IMPLEMENTED(pa_pstream_set_die_callback)
NOT_IMPLEMENTED(pa_pstream_set_drain_callback)
NOT_IMPLEMENTED(pa_pstream_set_receive_memblock_callback)
NOT_IMPLEMENTED(pa_pstream_set_receive_packet_callback)
NOT_IMPLEMENTED(pa_pstream_set_release_callback)
NOT_IMPLEMENTED(pa_pstream_set_revoke_callback)
NOT_IMPLEMENTED(pa_pstream_unlink)
NOT_IMPLEMENTED(pa_pstream_unref)
NOT_IMPLEMENTED(pa_queue_free)
NOT_IMPLEMENTED(pa_queue_isempty)
NOT_IMPLEMENTED(pa_queue_new)
NOT_IMPLEMENTED(pa_queue_pop)
NOT_IMPLEMENTED(pa_queue_push)
NOT_IMPLEMENTED(pa_raise_priority)
NOT_IMPLEMENTED(pa_random)
NOT_IMPLEMENTED(pa_random_seed)
NOT_IMPLEMENTED(pa_ratelimit_test)
NOT_IMPLEMENTED(pa_read)
NOT_IMPLEMENTED(pa_read_line_from_file)
NOT_IMPLEMENTED(pa_readlink)
NOT_IMPLEMENTED(pa_realpath)
NOT_IMPLEMENTED(pa_reduce)
NOT_IMPLEMENTED(pa_replace)
NOT_IMPLEMENTED(pa_reset_personality)
NOT_IMPLEMENTED(pa_reset_priority)
NOT_IMPLEMENTED(pa_reset_sigs)
NOT_IMPLEMENTED(pa_reset_sigsv)
NOT_IMPLEMENTED(pa_rtclock_age)
NOT_IMPLEMENTED(pa_rtclock_from_wallclock)
NOT_IMPLEMENTED(pa_rtclock_get)
NOT_IMPLEMENTED(pa_rtclock_hrtimer)
NOT_IMPLEMENTED(pa_rtclock_hrtimer_enable)
NOT_IMPLEMENTED(pa_rtclock_now)
NOT_IMPLEMENTED(pa_run_from_build_tree)
NOT_IMPLEMENTED(pa_run_once)
NOT_IMPLEMENTED(pa_running_in_vm)
NOT_IMPLEMENTED(pa_runtime_path)
NOT_IMPLEMENTED(pa_sample_clamp)
NOT_IMPLEMENTED(pa_sample_format_is_be)
NOT_IMPLEMENTED(pa_sample_format_is_le)
/*NOT_IMPLEMENTED(pa_sample_format_to_string)*/
NOT_IMPLEMENTED(pa_sample_format_valid)
NOT_IMPLEMENTED(pa_sample_rate_valid)
NOT_IMPLEMENTED(pa_sample_size)
NOT_IMPLEMENTED(pa_sample_size_of_format)
NOT_IMPLEMENTED(pa_sample_spec_equal)
NOT_IMPLEMENTED(pa_sample_spec_init)
/*NOT_IMPLEMENTED(pa_sample_spec_snprint)*/
/*NOT_IMPLEMENTED(pa_sample_spec_valid)*/
NOT_IMPLEMENTED(pa_semaphore_free)
NOT_IMPLEMENTED(pa_semaphore_new)
NOT_IMPLEMENTED(pa_semaphore_post)
NOT_IMPLEMENTED(pa_semaphore_wait)
NOT_IMPLEMENTED(pa_session_id)
NOT_IMPLEMENTED(pa_set_env)
NOT_IMPLEMENTED(pa_set_env_and_record)
NOT_IMPLEMENTED(pa_set_volume_func)
NOT_IMPLEMENTED(pa_shm_attach_ro)
NOT_IMPLEMENTED(pa_shm_cleanup)
NOT_IMPLEMENTED(pa_shm_create_rw)
NOT_IMPLEMENTED(pa_shm_free)
NOT_IMPLEMENTED(pa_shm_punch)
NOT_IMPLEMENTED(pa_sig2str)
NOT_IMPLEMENTED(pa_signal_done)
NOT_IMPLEMENTED(pa_signal_free)
NOT_IMPLEMENTED(pa_signal_init)
NOT_IMPLEMENTED(pa_signal_new)
NOT_IMPLEMENTED(pa_signal_set_destroy)
NOT_IMPLEMENTED(pa_silence_cache_done)
NOT_IMPLEMENTED(pa_silence_cache_init)
NOT_IMPLEMENTED(pa_silence_memblock)
NOT_IMPLEMENTED(pa_silence_memchunk)
NOT_IMPLEMENTED(pa_silence_memchunk_get)
NOT_IMPLEMENTED(pa_silence_memory)
NOT_IMPLEMENTED(pa_smoother_fix_now)
NOT_IMPLEMENTED(pa_smoother_free)
NOT_IMPLEMENTED(pa_smoother_get)
NOT_IMPLEMENTED(pa_smoother_new)
NOT_IMPLEMENTED(pa_smoother_pause)
NOT_IMPLEMENTED(pa_smoother_put)
NOT_IMPLEMENTED(pa_smoother_reset)
NOT_IMPLEMENTED(pa_smoother_resume)
NOT_IMPLEMENTED(pa_smoother_set_time_offset)
NOT_IMPLEMENTED(pa_smoother_translate)
NOT_IMPLEMENTED(pa_sndfile_dump_formats)
NOT_IMPLEMENTED(pa_sndfile_format_from_string)
NOT_IMPLEMENTED(pa_sndfile_init_proplist)
NOT_IMPLEMENTED(pa_sndfile_read_channel_map)
NOT_IMPLEMENTED(pa_sndfile_read_sample_spec)
NOT_IMPLEMENTED(pa_sndfile_readf_function)
NOT_IMPLEMENTED(pa_sndfile_write_channel_map)
NOT_IMPLEMENTED(pa_sndfile_write_sample_spec)
NOT_IMPLEMENTED(pa_sndfile_writef_function)
NOT_IMPLEMENTED(pa_snprintf)
NOT_IMPLEMENTED(pa_socket_address_is_local)
NOT_IMPLEMENTED(pa_socket_client_is_local)
NOT_IMPLEMENTED(pa_socket_client_new_ipv4)
NOT_IMPLEMENTED(pa_socket_client_new_ipv6)
NOT_IMPLEMENTED(pa_socket_client_new_sockaddr)
NOT_IMPLEMENTED(pa_socket_client_new_string)
NOT_IMPLEMENTED(pa_socket_client_new_unix)
NOT_IMPLEMENTED(pa_socket_client_ref)
NOT_IMPLEMENTED(pa_socket_client_set_callback)
NOT_IMPLEMENTED(pa_socket_client_unref)
NOT_IMPLEMENTED(pa_socket_cloexec)
NOT_IMPLEMENTED(pa_socket_is_local)
NOT_IMPLEMENTED(pa_socket_peer_to_string)
NOT_IMPLEMENTED(pa_socket_server_get_address)
NOT_IMPLEMENTED(pa_socket_server_new)
NOT_IMPLEMENTED(pa_socket_server_new_ipv4)
NOT_IMPLEMENTED(pa_socket_server_new_ipv4_any)
NOT_IMPLEMENTED(pa_socket_server_new_ipv4_loopback)
NOT_IMPLEMENTED(pa_socket_server_new_ipv4_string)
NOT_IMPLEMENTED(pa_socket_server_new_ipv6)
NOT_IMPLEMENTED(pa_socket_server_new_ipv6_any)
NOT_IMPLEMENTED(pa_socket_server_new_ipv6_loopback)
NOT_IMPLEMENTED(pa_socket_server_new_ipv6_string)
NOT_IMPLEMENTED(pa_socket_server_new_unix)
NOT_IMPLEMENTED(pa_socket_server_ref)
NOT_IMPLEMENTED(pa_socket_server_set_callback)
NOT_IMPLEMENTED(pa_socket_server_unref)
NOT_IMPLEMENTED(pa_socket_set_rcvbuf)
NOT_IMPLEMENTED(pa_socket_set_sndbuf)
NOT_IMPLEMENTED(pa_split)
NOT_IMPLEMENTED(pa_split_in_place)
NOT_IMPLEMENTED(pa_split_spaces)
NOT_IMPLEMENTED(pa_split_spaces_strv)
NOT_IMPLEMENTED(pa_sprintf_malloc)
NOT_IMPLEMENTED(pa_startswith)
NOT_IMPLEMENTED(pa_state_path)
NOT_IMPLEMENTED(pa_static_mutex_get)
NOT_IMPLEMENTED(pa_static_semaphore_get)
NOT_IMPLEMENTED(pa_str_in_list_spaces)
NOT_IMPLEMENTED(pa_strbuf_free)
NOT_IMPLEMENTED(pa_strbuf_isempty)
NOT_IMPLEMENTED(pa_strbuf_new)
NOT_IMPLEMENTED(pa_strbuf_printf)
NOT_IMPLEMENTED(pa_strbuf_putc)
NOT_IMPLEMENTED(pa_strbuf_puts)
NOT_IMPLEMENTED(pa_strbuf_putsn)
NOT_IMPLEMENTED(pa_strbuf_tostring)
NOT_IMPLEMENTED(pa_strbuf_tostring_free)
NOT_IMPLEMENTED(pa_stream_begin_write)
NOT_IMPLEMENTED(pa_stream_cancel_write)
/*NOT_IMPLEMENTED(pa_stream_connect_playback)*/
/*NOT_IMPLEMENTED(pa_stream_connect_record)*/
NOT_IMPLEMENTED(pa_stream_connect_upload)
/*NOT_IMPLEMENTED(pa_stream_cork)*/
/*NOT_IMPLEMENTED(pa_stream_disconnect)*/
NOT_IMPLEMENTED(pa_stream_drain)
/*NOT_IMPLEMENTED(pa_stream_drop)*/
NOT_IMPLEMENTED(pa_stream_finish_upload)
NOT_IMPLEMENTED(pa_stream_flush)
/*NOT_IMPLEMENTED(pa_stream_get_buffer_attr)*/
NOT_IMPLEMENTED(pa_stream_get_channel_map)
NOT_IMPLEMENTED(pa_stream_get_context)
/*NOT_IMPLEMENTED(pa_stream_get_device_index)*/
NOT_IMPLEMENTED(pa_stream_get_device_name)
NOT_IMPLEMENTED(pa_stream_get_format_info)
NOT_IMPLEMENTED(pa_stream_get_index)
NOT_IMPLEMENTED(pa_stream_get_latency)
NOT_IMPLEMENTED(pa_stream_get_monitor_stream)
/*NOT_IMPLEMENTED(pa_stream_get_sample_spec)*/
/*NOT_IMPLEMENTED(pa_stream_get_state)*/
NOT_IMPLEMENTED(pa_stream_get_time)
NOT_IMPLEMENTED(pa_stream_get_timing_info)
NOT_IMPLEMENTED(pa_stream_get_underflow_index)
NOT_IMPLEMENTED(pa_stream_is_corked)
NOT_IMPLEMENTED(pa_stream_is_suspended)
/*NOT_IMPLEMENTED(pa_stream_new)*/
NOT_IMPLEMENTED(pa_stream_new_extended)
NOT_IMPLEMENTED(pa_stream_new_with_proplist)
/*NOT_IMPLEMENTED(pa_stream_peek)*/
NOT_IMPLEMENTED(pa_stream_prebuf)
NOT_IMPLEMENTED(pa_stream_proplist_remove)
NOT_IMPLEMENTED(pa_stream_proplist_update)
NOT_IMPLEMENTED(pa_stream_readable_size)
NOT_IMPLEMENTED(pa_stream_ref)
NOT_IMPLEMENTED(pa_stream_set_buffer_attr)
NOT_IMPLEMENTED(pa_stream_set_buffer_attr_callback)
NOT_IMPLEMENTED(pa_stream_set_event_callback)
NOT_IMPLEMENTED(pa_stream_set_latency_update_callback)
NOT_IMPLEMENTED(pa_stream_set_monitor_stream)
NOT_IMPLEMENTED(pa_stream_set_moved_callback)
NOT_IMPLEMENTED(pa_stream_set_name)
NOT_IMPLEMENTED(pa_stream_set_overflow_callback)
/*NOT_IMPLEMENTED(pa_stream_set_read_callback)*/
NOT_IMPLEMENTED(pa_stream_set_started_callback)
/*NOT_IMPLEMENTED(pa_stream_set_state_callback)*/
NOT_IMPLEMENTED(pa_stream_set_suspended_callback)
/*NOT_IMPLEMENTED(pa_stream_set_underflow_callback)*/
/*NOT_IMPLEMENTED(pa_stream_set_write_callback)*/
/*NOT_IMPLEMENTED(pa_stream_trigger)*/
/*NOT_IMPLEMENTED(pa_stream_unref)*/
NOT_IMPLEMENTED(pa_stream_update_sample_rate)
NOT_IMPLEMENTED(pa_stream_update_timing_info)
NOT_IMPLEMENTED(pa_stream_writable_size)
/*NOT_IMPLEMENTED(pa_stream_write)*/
NOT_IMPLEMENTED(pa_strerror)
NOT_IMPLEMENTED(pa_strip)
NOT_IMPLEMENTED(pa_strip_nl)
NOT_IMPLEMENTED(pa_strlcpy)
NOT_IMPLEMENTED(pa_strlist_data)
NOT_IMPLEMENTED(pa_strlist_free)
NOT_IMPLEMENTED(pa_strlist_next)
NOT_IMPLEMENTED(pa_strlist_parse)
NOT_IMPLEMENTED(pa_strlist_pop)
NOT_IMPLEMENTED(pa_strlist_prepend)
NOT_IMPLEMENTED(pa_strlist_remove)
NOT_IMPLEMENTED(pa_strlist_reverse)
NOT_IMPLEMENTED(pa_strlist_tostring)
NOT_IMPLEMENTED(pa_sw_cvolume_divide)
NOT_IMPLEMENTED(pa_sw_cvolume_divide_scalar)
NOT_IMPLEMENTED(pa_sw_cvolume_multiply)
NOT_IMPLEMENTED(pa_sw_cvolume_multiply_scalar)
NOT_IMPLEMENTED(pa_sw_cvolume_snprint_dB)
NOT_IMPLEMENTED(pa_sw_volume_divide)
NOT_IMPLEMENTED(pa_sw_volume_from_dB)
NOT_IMPLEMENTED(pa_sw_volume_from_linear)
NOT_IMPLEMENTED(pa_sw_volume_multiply)
NOT_IMPLEMENTED(pa_sw_volume_snprint_dB)
NOT_IMPLEMENTED(pa_sw_volume_to_dB)
NOT_IMPLEMENTED(pa_sw_volume_to_linear)
NOT_IMPLEMENTED(pa_tagstruct_data)
NOT_IMPLEMENTED(pa_tagstruct_eof)
NOT_IMPLEMENTED(pa_tagstruct_free)
NOT_IMPLEMENTED(pa_tagstruct_free_data)
NOT_IMPLEMENTED(pa_tagstruct_get)
NOT_IMPLEMENTED(pa_tagstruct_get_arbitrary)
NOT_IMPLEMENTED(pa_tagstruct_get_boolean)
NOT_IMPLEMENTED(pa_tagstruct_get_channel_map)
NOT_IMPLEMENTED(pa_tagstruct_get_cvolume)
NOT_IMPLEMENTED(pa_tagstruct_get_format_info)
NOT_IMPLEMENTED(pa_tagstruct_get_proplist)
NOT_IMPLEMENTED(pa_tagstruct_get_sample_spec)
NOT_IMPLEMENTED(pa_tagstruct_get_timeval)
NOT_IMPLEMENTED(pa_tagstruct_get_usec)
NOT_IMPLEMENTED(pa_tagstruct_get_volume)
NOT_IMPLEMENTED(pa_tagstruct_gets)
NOT_IMPLEMENTED(pa_tagstruct_gets64)
NOT_IMPLEMENTED(pa_tagstruct_getu32)
NOT_IMPLEMENTED(pa_tagstruct_getu64)
NOT_IMPLEMENTED(pa_tagstruct_getu8)
NOT_IMPLEMENTED(pa_tagstruct_new)
NOT_IMPLEMENTED(pa_tagstruct_put)
NOT_IMPLEMENTED(pa_tagstruct_put_arbitrary)
NOT_IMPLEMENTED(pa_tagstruct_put_boolean)
NOT_IMPLEMENTED(pa_tagstruct_put_channel_map)
NOT_IMPLEMENTED(pa_tagstruct_put_cvolume)
NOT_IMPLEMENTED(pa_tagstruct_put_format_info)
NOT_IMPLEMENTED(pa_tagstruct_put_proplist)
NOT_IMPLEMENTED(pa_tagstruct_put_sample_spec)
NOT_IMPLEMENTED(pa_tagstruct_put_timeval)
NOT_IMPLEMENTED(pa_tagstruct_put_usec)
NOT_IMPLEMENTED(pa_tagstruct_put_volume)
NOT_IMPLEMENTED(pa_tagstruct_puts)
NOT_IMPLEMENTED(pa_tagstruct_puts64)
NOT_IMPLEMENTED(pa_tagstruct_putu32)
NOT_IMPLEMENTED(pa_tagstruct_putu64)
NOT_IMPLEMENTED(pa_tagstruct_putu8)
NOT_IMPLEMENTED(pa_thread_free)
NOT_IMPLEMENTED(pa_thread_free_nojoin)
NOT_IMPLEMENTED(pa_thread_get_data)
NOT_IMPLEMENTED(pa_thread_get_name)
NOT_IMPLEMENTED(pa_thread_is_running)
NOT_IMPLEMENTED(pa_thread_join)
NOT_IMPLEMENTED(pa_thread_new)
NOT_IMPLEMENTED(pa_thread_self)
NOT_IMPLEMENTED(pa_thread_set_data)
NOT_IMPLEMENTED(pa_thread_set_name)
NOT_IMPLEMENTED(pa_thread_yield)
NOT_IMPLEMENTED(pa_threaded_mainloop_accept)
/*NOT_IMPLEMENTED(pa_threaded_mainloop_free)*/
/*NOT_IMPLEMENTED(pa_threaded_mainloop_get_api)*/
NOT_IMPLEMENTED(pa_threaded_mainloop_get_retval)
/*NOT_IMPLEMENTED(pa_threaded_mainloop_in_thread)*/
/*NOT_IMPLEMENTED(pa_threaded_mainloop_lock)*/
/*NOT_IMPLEMENTED(pa_threaded_mainloop_new)*/
NOT_IMPLEMENTED(pa_threaded_mainloop_set_name)
/*NOT_IMPLEMENTED(pa_threaded_mainloop_signal)*/
/*NOT_IMPLEMENTED(pa_threaded_mainloop_start)*/
NOT_IMPLEMENTED(pa_threaded_mainloop_stop)
/*NOT_IMPLEMENTED(pa_threaded_mainloop_unlock)*/
/*NOT_IMPLEMENTED(pa_threaded_mainloop_wait)*/
NOT_IMPLEMENTED(pa_timespec_load)
NOT_IMPLEMENTED(pa_timespec_store)
NOT_IMPLEMENTED(pa_timeval_add)
NOT_IMPLEMENTED(pa_timeval_age)
NOT_IMPLEMENTED(pa_timeval_cmp)
NOT_IMPLEMENTED(pa_timeval_diff)
NOT_IMPLEMENTED(pa_timeval_load)
NOT_IMPLEMENTED(pa_timeval_rtstore)
NOT_IMPLEMENTED(pa_timeval_store)
NOT_IMPLEMENTED(pa_timeval_sub)
NOT_IMPLEMENTED(pa_tls_free)
NOT_IMPLEMENTED(pa_tls_get)
NOT_IMPLEMENTED(pa_tls_new)
NOT_IMPLEMENTED(pa_tls_set)
NOT_IMPLEMENTED(pa_tokenizer_free)
NOT_IMPLEMENTED(pa_tokenizer_get)
NOT_IMPLEMENTED(pa_tokenizer_new)
NOT_IMPLEMENTED(pa_truncate_utf8)
NOT_IMPLEMENTED(pa_uid_in_group)
NOT_IMPLEMENTED(pa_uname_string)
NOT_IMPLEMENTED(pa_unblock_sigs)
NOT_IMPLEMENTED(pa_unblock_sigsv)
NOT_IMPLEMENTED(pa_unescape)
NOT_IMPLEMENTED(pa_unix_socket_is_stale)
NOT_IMPLEMENTED(pa_unix_socket_remove_stale)
NOT_IMPLEMENTED(pa_unlock_lockfile)
NOT_IMPLEMENTED(pa_unset_env_recorded)
/*NOT_IMPLEMENTED(pa_usec_to_bytes)*/
NOT_IMPLEMENTED(pa_usec_to_bytes_round_up)
NOT_IMPLEMENTED(pa_utf8_filter)
NOT_IMPLEMENTED(pa_utf8_to_locale)
NOT_IMPLEMENTED(pa_utf8_valid)
NOT_IMPLEMENTED(pa_volume_func_init_arm)
NOT_IMPLEMENTED(pa_volume_func_init_mmx)
NOT_IMPLEMENTED(pa_volume_func_init_sse)
NOT_IMPLEMENTED(pa_volume_snprint)
NOT_IMPLEMENTED(pa_volume_snprint_verbose)
NOT_IMPLEMENTED(pa_vsnprintf)
NOT_IMPLEMENTED(pa_vsprintf_malloc)
NOT_IMPLEMENTED(pa_will_need)
NOT_IMPLEMENTED(pa_write)
NOT_IMPLEMENTED(pa_x11_del_prop)
NOT_IMPLEMENTED(pa_x11_get_prop)
NOT_IMPLEMENTED(pa_x11_set_prop)
NOT_IMPLEMENTED(pa_xfree)
NOT_IMPLEMENTED(pa_xfreev)
NOT_IMPLEMENTED(pa_xmalloc)
NOT_IMPLEMENTED(pa_xmalloc0)
NOT_IMPLEMENTED(pa_xmemdup)
NOT_IMPLEMENTED(pa_xrealloc)
NOT_IMPLEMENTED(pa_xstrdup)
