#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/soundcard.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>

int pa_accept_cloexec(){ printf("pa_accept_cloexec\n");}
int pa_ascii_filter(){ printf("pa_ascii_filter\n");}
int pa_ascii_valid(){ printf("pa_ascii_valid\n");}
int pa_atod(){ printf("pa_atod\n");}
int pa_atoi(){ printf("pa_atoi\n");}
int pa_atol(){ printf("pa_atol\n");}
int pa_atou(){ printf("pa_atou\n");}
int pa_aupdate_free(){ printf("pa_aupdate_free\n");}
int pa_aupdate_new(){ printf("pa_aupdate_new\n");}
int pa_aupdate_read_begin(){ printf("pa_aupdate_read_begin\n");}
int pa_aupdate_read_end(){ printf("pa_aupdate_read_end\n");}
int pa_aupdate_write_begin(){ printf("pa_aupdate_write_begin\n");}
int pa_aupdate_write_end(){ printf("pa_aupdate_write_end\n");}
int pa_aupdate_write_swap(){ printf("pa_aupdate_write_swap\n");}
int pa_authkey_load(){ printf("pa_authkey_load\n");}
int pa_authkey_load_auto(){ printf("pa_authkey_load_auto\n");}
int pa_authkey_save(){ printf("pa_authkey_save\n");}
int pa_autospawn_lock_acquire(){ printf("pa_autospawn_lock_acquire\n");}
int pa_autospawn_lock_done(){ printf("pa_autospawn_lock_done\n");}
int pa_autospawn_lock_init(){ printf("pa_autospawn_lock_init\n");}
int pa_autospawn_lock_release(){ printf("pa_autospawn_lock_release\n");}
int pa_bitset_equals(){ printf("pa_bitset_equals\n");}
int pa_bitset_get(){ printf("pa_bitset_get\n");}
int pa_bitset_set(){ printf("pa_bitset_set\n");}
int pa_bytes_per_second(){ printf("pa_bytes_per_second\n");}
int pa_bytes_snprint(){ printf("pa_bytes_snprint\n");}
int pa_bytes_to_usec(){ printf("pa_bytes_to_usec\n");}
int pa_bytes_to_usec_round_up(){ printf("pa_bytes_to_usec_round_up\n");}
int pa_channel_map_can_balance(){ printf("pa_channel_map_can_balance\n");}
int pa_channel_map_can_fade(){ printf("pa_channel_map_can_fade\n");}
int pa_channel_map_compatible(){ printf("pa_channel_map_compatible\n");}
int pa_channel_map_equal(){ printf("pa_channel_map_equal\n");}
int pa_channel_map_has_position(){ printf("pa_channel_map_has_position\n");}
int pa_channel_map_init(){ printf("pa_channel_map_init\n");}
int pa_channel_map_init_auto(){ printf("pa_channel_map_init_auto\n");}
int pa_channel_map_init_extend(){ printf("pa_channel_map_init_extend\n");}
/*int pa_channel_map_init_mono(){ printf("pa_channel_map_init_mono\n");}*/
/*int pa_channel_map_init_stereo(){ printf("pa_channel_map_init_stereo\n");}*/
int pa_channel_map_mask(){ printf("pa_channel_map_mask\n");}
int pa_channel_map_parse(){ printf("pa_channel_map_parse\n");}
int pa_channel_map_snprint(){ printf("pa_channel_map_snprint\n");}
int pa_channel_map_superset(){ printf("pa_channel_map_superset\n");}
int pa_channel_map_to_name(){ printf("pa_channel_map_to_name\n");}
int pa_channel_map_to_pretty_name(){ printf("pa_channel_map_to_pretty_name\n");}
int pa_channel_map_valid(){ printf("pa_channel_map_valid\n");}
int pa_channel_position_from_string(){ printf("pa_channel_position_from_string\n");}
int pa_channel_position_to_pretty_string(){ printf("pa_channel_position_to_pretty_string\n");}
int pa_channel_position_to_string(){ printf("pa_channel_position_to_string\n");}
int pa_channels_valid(){ printf("pa_channels_valid\n");}
int pa_check_in_group(){ printf("pa_check_in_group\n");}
int pa_check_signal_is_blocked(){ printf("pa_check_signal_is_blocked\n");}
int pa_client_conf_env(){ printf("pa_client_conf_env\n");}
int pa_client_conf_free(){ printf("pa_client_conf_free\n");}
int pa_client_conf_from_x11(){ printf("pa_client_conf_from_x11\n");}
int pa_client_conf_load(){ printf("pa_client_conf_load\n");}
int pa_client_conf_load_cookie_from_file(){ printf("pa_client_conf_load_cookie_from_file\n");}
int pa_client_conf_load_cookie_from_hex(){ printf("pa_client_conf_load_cookie_from_hex\n");}
int pa_client_conf_new(){ printf("pa_client_conf_new\n");}
int pa_client_conf_set_cookie(){ printf("pa_client_conf_set_cookie\n");}
int pa_close(){ printf("pa_close\n");}
int pa_close_all(){ printf("pa_close_all\n");}
int pa_close_allv(){ printf("pa_close_allv\n");}
int pa_close_pipe(){ printf("pa_close_pipe\n");}
int pa_cond_free(){ printf("pa_cond_free\n");}
int pa_cond_new(){ printf("pa_cond_new\n");}
int pa_cond_signal(){ printf("pa_cond_signal\n");}
int pa_cond_wait(){ printf("pa_cond_wait\n");}
int pa_config_parse(){ printf("pa_config_parse\n");}
int pa_config_parse_bool(){ printf("pa_config_parse_bool\n");}
int pa_config_parse_int(){ printf("pa_config_parse_int\n");}
int pa_config_parse_not_bool(){ printf("pa_config_parse_not_bool\n");}
int pa_config_parse_size(){ printf("pa_config_parse_size\n");}
int pa_config_parse_string(){ printf("pa_config_parse_string\n");}
int pa_config_parse_unsigned(){ printf("pa_config_parse_unsigned\n");}
int pa_context_add_autoload(){ printf("pa_context_add_autoload\n");}
/*int pa_context_connect(){ printf("pa_context_connect\n");}*/
int pa_context_disconnect(){ printf("pa_context_disconnect\n");}
/*int pa_context_drain(){ printf("pa_context_drain\n");}*/
int pa_context_errno(){ printf("pa_context_errno\n");}
int pa_context_exit_daemon(){ printf("pa_context_exit_daemon\n");}
int pa_context_get_autoload_info_by_index(){ printf("pa_context_get_autoload_info_by_index\n");}
int pa_context_get_autoload_info_by_name(){ printf("pa_context_get_autoload_info_by_name\n");}
int pa_context_get_autoload_info_list(){ printf("pa_context_get_autoload_info_list\n");}
int pa_context_get_card_info_by_index(){ printf("pa_context_get_card_info_by_index\n");}
int pa_context_get_card_info_by_name(){ printf("pa_context_get_card_info_by_name\n");}
int pa_context_get_card_info_list(){ printf("pa_context_get_card_info_list\n");}
int pa_context_get_client_info(){ printf("pa_context_get_client_info\n");}
int pa_context_get_client_info_list(){ printf("pa_context_get_client_info_list\n");}
int pa_context_get_index(){ printf("pa_context_get_index\n");}
int pa_context_get_module_info(){ printf("pa_context_get_module_info\n");}
int pa_context_get_module_info_list(){ printf("pa_context_get_module_info_list\n");}
int pa_context_get_protocol_version(){ printf("pa_context_get_protocol_version\n");}
int pa_context_get_sample_info_by_index(){ printf("pa_context_get_sample_info_by_index\n");}
int pa_context_get_sample_info_by_name(){ printf("pa_context_get_sample_info_by_name\n");}
int pa_context_get_sample_info_list(){ printf("pa_context_get_sample_info_list\n");}
int pa_context_get_server(){ printf("pa_context_get_server\n");}
int pa_context_get_server_info(){ printf("pa_context_get_server_info\n");}
int pa_context_get_server_protocol_version(){ printf("pa_context_get_server_protocol_version\n");}
int pa_context_get_sink_info_by_index(){ printf("pa_context_get_sink_info_by_index\n");}
int pa_context_get_sink_info_by_name(){ printf("pa_context_get_sink_info_by_name\n");}
int pa_context_get_sink_info_list(){ printf("pa_context_get_sink_info_list\n");}
int pa_context_get_sink_input_info(){ printf("pa_context_get_sink_input_info\n");}
int pa_context_get_sink_input_info_list(){ printf("pa_context_get_sink_input_info_list\n");}
int pa_context_get_source_info_by_index(){ printf("pa_context_get_source_info_by_index\n");}
int pa_context_get_source_info_by_name(){ printf("pa_context_get_source_info_by_name\n");}
int pa_context_get_source_info_list(){ printf("pa_context_get_source_info_list\n");}
int pa_context_get_source_output_info(){ printf("pa_context_get_source_output_info\n");}
int pa_context_get_source_output_info_list(){ printf("pa_context_get_source_output_info_list\n");}
/*int pa_context_get_state(){ printf("pa_context_get_state\n");}*/
int pa_context_get_tile_size(){ printf("pa_context_get_tile_size\n");}
int pa_context_is_local(){ printf("pa_context_is_local\n");}
int pa_context_is_pending(){ printf("pa_context_is_pending\n");}
int pa_context_kill_client(){ printf("pa_context_kill_client\n");}
int pa_context_kill_sink_input(){ printf("pa_context_kill_sink_input\n");}
int pa_context_kill_source_output(){ printf("pa_context_kill_source_output\n");}
int pa_context_load_cookie_from_file(){ printf("pa_context_load_cookie_from_file\n");}
int pa_context_load_module(){ printf("pa_context_load_module\n");}
int pa_context_move_sink_input_by_index(){ printf("pa_context_move_sink_input_by_index\n");}
int pa_context_move_sink_input_by_name(){ printf("pa_context_move_sink_input_by_name\n");}
int pa_context_move_source_output_by_index(){ printf("pa_context_move_source_output_by_index\n");}
int pa_context_move_source_output_by_name(){ printf("pa_context_move_source_output_by_name\n");}
/*int pa_context_new(){ printf("pa_context_new\n");}*/
int pa_context_new_with_proplist(){ printf("pa_context_new_with_proplist\n");}
int pa_context_play_sample(){ printf("pa_context_play_sample\n");}
int pa_context_play_sample_with_proplist(){ printf("pa_context_play_sample_with_proplist\n");}
int pa_context_proplist_remove(){ printf("pa_context_proplist_remove\n");}
int pa_context_proplist_update(){ printf("pa_context_proplist_update\n");}
int pa_context_ref(){ printf("pa_context_ref\n");}
int pa_context_remove_autoload_by_index(){ printf("pa_context_remove_autoload_by_index\n");}
int pa_context_remove_autoload_by_name(){ printf("pa_context_remove_autoload_by_name\n");}
int pa_context_remove_sample(){ printf("pa_context_remove_sample\n");}
int pa_context_rttime_new(){ printf("pa_context_rttime_new\n");}
int pa_context_rttime_restart(){ printf("pa_context_rttime_restart\n");}
int pa_context_set_card_profile_by_index(){ printf("pa_context_set_card_profile_by_index\n");}
int pa_context_set_card_profile_by_name(){ printf("pa_context_set_card_profile_by_name\n");}
int pa_context_set_default_sink(){ printf("pa_context_set_default_sink\n");}
int pa_context_set_default_source(){ printf("pa_context_set_default_source\n");}
int pa_context_set_event_callback(){ printf("pa_context_set_event_callback\n");}
int pa_context_set_name(){ printf("pa_context_set_name\n");}
int pa_context_set_port_latency_offset(){ printf("pa_context_set_port_latency_offset\n");}
int pa_context_set_sink_input_mute(){ printf("pa_context_set_sink_input_mute\n");}
int pa_context_set_sink_input_volume(){ printf("pa_context_set_sink_input_volume\n");}
int pa_context_set_sink_mute_by_index(){ printf("pa_context_set_sink_mute_by_index\n");}
int pa_context_set_sink_mute_by_name(){ printf("pa_context_set_sink_mute_by_name\n");}
int pa_context_set_sink_port_by_index(){ printf("pa_context_set_sink_port_by_index\n");}
int pa_context_set_sink_port_by_name(){ printf("pa_context_set_sink_port_by_name\n");}
int pa_context_set_sink_volume_by_index(){ printf("pa_context_set_sink_volume_by_index\n");}
int pa_context_set_sink_volume_by_name(){ printf("pa_context_set_sink_volume_by_name\n");}
int pa_context_set_source_mute_by_index(){ printf("pa_context_set_source_mute_by_index\n");}
int pa_context_set_source_mute_by_name(){ printf("pa_context_set_source_mute_by_name\n");}
int pa_context_set_source_output_mute(){ printf("pa_context_set_source_output_mute\n");}
int pa_context_set_source_output_volume(){ printf("pa_context_set_source_output_volume\n");}
int pa_context_set_source_port_by_index(){ printf("pa_context_set_source_port_by_index\n");}
int pa_context_set_source_port_by_name(){ printf("pa_context_set_source_port_by_name\n");}
int pa_context_set_source_volume_by_index(){ printf("pa_context_set_source_volume_by_index\n");}
int pa_context_set_source_volume_by_name(){ printf("pa_context_set_source_volume_by_name\n");}
/*int pa_context_set_state_callback(){ printf("pa_context_set_state_callback\n");}*/
/*int pa_context_set_subscribe_callback(){ printf("pa_context_set_subscribe_callback\n");}*/
int pa_context_stat(){ printf("pa_context_stat\n");}
/*int pa_context_subscribe(){ printf("pa_context_subscribe\n");}*/
int pa_context_suspend_sink_by_index(){ printf("pa_context_suspend_sink_by_index\n");}
int pa_context_suspend_sink_by_name(){ printf("pa_context_suspend_sink_by_name\n");}
int pa_context_suspend_source_by_index(){ printf("pa_context_suspend_source_by_index\n");}
int pa_context_suspend_source_by_name(){ printf("pa_context_suspend_source_by_name\n");}
int pa_context_unload_module(){ printf("pa_context_unload_module\n");}
int pa_context_unref(){ printf("pa_context_unref\n");}
int pa_convert_size(){ printf("pa_convert_size\n");}
int pa_cstrerror(){ printf("pa_cstrerror\n");}
int pa_cvolume_avg(){ printf("pa_cvolume_avg\n");}
int pa_cvolume_avg_mask(){ printf("pa_cvolume_avg_mask\n");}
int pa_cvolume_channels_equal_to(){ printf("pa_cvolume_channels_equal_to\n");}
int pa_cvolume_compatible(){ printf("pa_cvolume_compatible\n");}
int pa_cvolume_compatible_with_channel_map(){ printf("pa_cvolume_compatible_with_channel_map\n");}
int pa_cvolume_dec(){ printf("pa_cvolume_dec\n");}
int pa_cvolume_equal(){ printf("pa_cvolume_equal\n");}
int pa_cvolume_get_balance(){ printf("pa_cvolume_get_balance\n");}
int pa_cvolume_get_fade(){ printf("pa_cvolume_get_fade\n");}
int pa_cvolume_get_position(){ printf("pa_cvolume_get_position\n");}
int pa_cvolume_inc(){ printf("pa_cvolume_inc\n");}
int pa_cvolume_inc_clamp(){ printf("pa_cvolume_inc_clamp\n");}
int pa_cvolume_init(){ printf("pa_cvolume_init\n");}
int pa_cvolume_max(){ printf("pa_cvolume_max\n");}
int pa_cvolume_max_mask(){ printf("pa_cvolume_max_mask\n");}
int pa_cvolume_merge(){ printf("pa_cvolume_merge\n");}
int pa_cvolume_min(){ printf("pa_cvolume_min\n");}
int pa_cvolume_min_mask(){ printf("pa_cvolume_min_mask\n");}
int pa_cvolume_remap(){ printf("pa_cvolume_remap\n");}
int pa_cvolume_scale(){ printf("pa_cvolume_scale\n");}
int pa_cvolume_scale_mask(){ printf("pa_cvolume_scale_mask\n");}
/*int pa_cvolume_set(){ printf("pa_cvolume_set\n");}*/
int pa_cvolume_set_balance(){ printf("pa_cvolume_set_balance\n");}
int pa_cvolume_set_fade(){ printf("pa_cvolume_set_fade\n");}
int pa_cvolume_set_position(){ printf("pa_cvolume_set_position\n");}
int pa_cvolume_snprint(){ printf("pa_cvolume_snprint\n");}
int pa_cvolume_snprint_verbose(){ printf("pa_cvolume_snprint_verbose\n");}
int pa_cvolume_valid(){ printf("pa_cvolume_valid\n");}
int pa_deinterleave(){ printf("pa_deinterleave\n");}
int pa_detect_fork(){ printf("pa_detect_fork\n");}
int pa_disable_sigpipe(){ printf("pa_disable_sigpipe\n");}
int pa_dynarray_append(){ printf("pa_dynarray_append\n");}
int pa_dynarray_free(){ printf("pa_dynarray_free\n");}
int pa_dynarray_get(){ printf("pa_dynarray_get\n");}
int pa_dynarray_new(){ printf("pa_dynarray_new\n");}
int pa_dynarray_size(){ printf("pa_dynarray_size\n");}
int pa_dynarray_steal_last(){ printf("pa_dynarray_steal_last\n");}
int pa_encoding_from_string(){ printf("pa_encoding_from_string\n");}
int pa_encoding_to_string(){ printf("pa_encoding_to_string\n");}
int pa_endswith(){ printf("pa_endswith\n");}
int pa_escape(){ printf("pa_escape\n");}
int pa_ext_device_manager_delete(){ printf("pa_ext_device_manager_delete\n");}
int pa_ext_device_manager_enable_role_device_priority_routing(){ printf("pa_ext_device_manager_enable_role_device_priority_routing\n");}
int pa_ext_device_manager_read(){ printf("pa_ext_device_manager_read\n");}
int pa_ext_device_manager_reorder_devices_for_role(){ printf("pa_ext_device_manager_reorder_devices_for_role\n");}
int pa_ext_device_manager_set_device_description(){ printf("pa_ext_device_manager_set_device_description\n");}
int pa_ext_device_manager_set_subscribe_cb(){ printf("pa_ext_device_manager_set_subscribe_cb\n");}
int pa_ext_device_manager_subscribe(){ printf("pa_ext_device_manager_subscribe\n");}
int pa_ext_device_manager_test(){ printf("pa_ext_device_manager_test\n");}
int pa_ext_device_restore_read_formats(){ printf("pa_ext_device_restore_read_formats\n");}
int pa_ext_device_restore_read_formats_all(){ printf("pa_ext_device_restore_read_formats_all\n");}
int pa_ext_device_restore_save_formats(){ printf("pa_ext_device_restore_save_formats\n");}
int pa_ext_device_restore_set_subscribe_cb(){ printf("pa_ext_device_restore_set_subscribe_cb\n");}
int pa_ext_device_restore_subscribe(){ printf("pa_ext_device_restore_subscribe\n");}
int pa_ext_device_restore_test(){ printf("pa_ext_device_restore_test\n");}
int pa_ext_stream_restore_delete(){ printf("pa_ext_stream_restore_delete\n");}
int pa_ext_stream_restore_read(){ printf("pa_ext_stream_restore_read\n");}
int pa_ext_stream_restore_set_subscribe_cb(){ printf("pa_ext_stream_restore_set_subscribe_cb\n");}
int pa_ext_stream_restore_subscribe(){ printf("pa_ext_stream_restore_subscribe\n");}
int pa_ext_stream_restore_test(){ printf("pa_ext_stream_restore_test\n");}
int pa_ext_stream_restore_write(){ printf("pa_ext_stream_restore_write\n");}
int pa_find_config_file(){ printf("pa_find_config_file\n");}
int pa_flist_free(){ printf("pa_flist_free\n");}
int pa_flist_new(){ printf("pa_flist_new\n");}
int pa_flist_new_with_name(){ printf("pa_flist_new_with_name\n");}
int pa_flist_pop(){ printf("pa_flist_pop\n");}
int pa_flist_push(){ printf("pa_flist_push\n");}
int pa_fopen_cloexec(){ printf("pa_fopen_cloexec\n");}
int pa_format_info_copy(){ printf("pa_format_info_copy\n");}
int pa_format_info_free(){ printf("pa_format_info_free\n");}
int pa_format_info_free_string_array(){ printf("pa_format_info_free_string_array\n");}
int pa_format_info_from_sample_spec(){ printf("pa_format_info_from_sample_spec\n");}
int pa_format_info_from_sample_spec2(){ printf("pa_format_info_from_sample_spec2\n");}
int pa_format_info_from_string(){ printf("pa_format_info_from_string\n");}
int pa_format_info_get_channel_map(){ printf("pa_format_info_get_channel_map\n");}
int pa_format_info_get_channels(){ printf("pa_format_info_get_channels\n");}
int pa_format_info_get_prop_int(){ printf("pa_format_info_get_prop_int\n");}
int pa_format_info_get_prop_int_array(){ printf("pa_format_info_get_prop_int_array\n");}
int pa_format_info_get_prop_int_range(){ printf("pa_format_info_get_prop_int_range\n");}
int pa_format_info_get_prop_string(){ printf("pa_format_info_get_prop_string\n");}
int pa_format_info_get_prop_string_array(){ printf("pa_format_info_get_prop_string_array\n");}
int pa_format_info_get_prop_type(){ printf("pa_format_info_get_prop_type\n");}
int pa_format_info_get_rate(){ printf("pa_format_info_get_rate\n");}
int pa_format_info_get_sample_format(){ printf("pa_format_info_get_sample_format\n");}
int pa_format_info_is_compatible(){ printf("pa_format_info_is_compatible\n");}
int pa_format_info_is_pcm(){ printf("pa_format_info_is_pcm\n");}
int pa_format_info_new(){ printf("pa_format_info_new\n");}
int pa_format_info_set_channel_map(){ printf("pa_format_info_set_channel_map\n");}
int pa_format_info_set_channels(){ printf("pa_format_info_set_channels\n");}
int pa_format_info_set_prop_int(){ printf("pa_format_info_set_prop_int\n");}
int pa_format_info_set_prop_int_array(){ printf("pa_format_info_set_prop_int_array\n");}
int pa_format_info_set_prop_int_range(){ printf("pa_format_info_set_prop_int_range\n");}
int pa_format_info_set_prop_string(){ printf("pa_format_info_set_prop_string\n");}
int pa_format_info_set_prop_string_array(){ printf("pa_format_info_set_prop_string_array\n");}
int pa_format_info_set_rate(){ printf("pa_format_info_set_rate\n");}
int pa_format_info_set_sample_format(){ printf("pa_format_info_set_sample_format\n");}
int pa_format_info_snprint(){ printf("pa_format_info_snprint\n");}
int pa_format_info_to_sample_spec(){ printf("pa_format_info_to_sample_spec\n");}
int pa_format_info_to_sample_spec2(){ printf("pa_format_info_to_sample_spec2\n");}
int pa_format_info_to_sample_spec_fake(){ printf("pa_format_info_to_sample_spec_fake\n");}
int pa_format_info_valid(){ printf("pa_format_info_valid\n");}
int pa_frame_align(){ printf("pa_frame_align\n");}
int pa_frame_aligned(){ printf("pa_frame_aligned\n");}
/*int pa_frame_size(){ printf("pa_frame_size\n");}*/
int pa_gcd(){ printf("pa_gcd\n");}
int pa_get_binary_name(){ printf("pa_get_binary_name\n");}
int pa_get_binary_name_malloc(){ printf("pa_get_binary_name_malloc\n");}
int pa_get_fqdn(){ printf("pa_get_fqdn\n");}
int pa_get_gid_of_group(){ printf("pa_get_gid_of_group\n");}
int pa_get_home_dir(){ printf("pa_get_home_dir\n");}
int pa_get_home_dir_malloc(){ printf("pa_get_home_dir_malloc\n");}
int pa_get_host_name(){ printf("pa_get_host_name\n");}
int pa_get_host_name_malloc(){ printf("pa_get_host_name_malloc\n");}
/* int pa_get_library_version(){ printf("pa_get_library_version\n");} */
int pa_get_runtime_dir(){ printf("pa_get_runtime_dir\n");}
int pa_get_state_dir(){ printf("pa_get_state_dir\n");}
int pa_get_temp_dir(){ printf("pa_get_temp_dir\n");}
int pa_get_user_name(){ printf("pa_get_user_name\n");}
int pa_get_user_name_malloc(){ printf("pa_get_user_name_malloc\n");}
int pa_get_volume_func(){ printf("pa_get_volume_func\n");}
int pa_getcwd(){ printf("pa_getcwd\n");}
int pa_getgrgid_free(){ printf("pa_getgrgid_free\n");}
int pa_getgrgid_malloc(){ printf("pa_getgrgid_malloc\n");}
int pa_getgrnam_free(){ printf("pa_getgrnam_free\n");}
int pa_getgrnam_malloc(){ printf("pa_getgrnam_malloc\n");}
int pa_getpwnam_free(){ printf("pa_getpwnam_free\n");}
int pa_getpwnam_malloc(){ printf("pa_getpwnam_malloc\n");}
int pa_getpwuid_free(){ printf("pa_getpwuid_free\n");}
int pa_getpwuid_malloc(){ printf("pa_getpwuid_malloc\n");}
int pa_gettimeofday(){ printf("pa_gettimeofday\n");}
int pa_hashmap_first(){ printf("pa_hashmap_first\n");}
int pa_hashmap_free(){ printf("pa_hashmap_free\n");}
int pa_hashmap_get(){ printf("pa_hashmap_get\n");}
int pa_hashmap_isempty(){ printf("pa_hashmap_isempty\n");}
int pa_hashmap_iterate(){ printf("pa_hashmap_iterate\n");}
int pa_hashmap_iterate_backwards(){ printf("pa_hashmap_iterate_backwards\n");}
int pa_hashmap_last(){ printf("pa_hashmap_last\n");}
int pa_hashmap_new(){ printf("pa_hashmap_new\n");}
int pa_hashmap_new_full(){ printf("pa_hashmap_new_full\n");}
int pa_hashmap_put(){ printf("pa_hashmap_put\n");}
int pa_hashmap_remove(){ printf("pa_hashmap_remove\n");}
int pa_hashmap_remove_all(){ printf("pa_hashmap_remove_all\n");}
int pa_hashmap_size(){ printf("pa_hashmap_size\n");}
int pa_hashmap_steal_first(){ printf("pa_hashmap_steal_first\n");}
int pa_hexstr(){ printf("pa_hexstr\n");}
int pa_idxset_copy(){ printf("pa_idxset_copy\n");}
int pa_idxset_first(){ printf("pa_idxset_first\n");}
int pa_idxset_free(){ printf("pa_idxset_free\n");}
int pa_idxset_get_by_data(){ printf("pa_idxset_get_by_data\n");}
int pa_idxset_get_by_index(){ printf("pa_idxset_get_by_index\n");}
int pa_idxset_isempty(){ printf("pa_idxset_isempty\n");}
int pa_idxset_iterate(){ printf("pa_idxset_iterate\n");}
int pa_idxset_new(){ printf("pa_idxset_new\n");}
int pa_idxset_next(){ printf("pa_idxset_next\n");}
int pa_idxset_put(){ printf("pa_idxset_put\n");}
int pa_idxset_remove_all(){ printf("pa_idxset_remove_all\n");}
int pa_idxset_remove_by_data(){ printf("pa_idxset_remove_by_data\n");}
int pa_idxset_remove_by_index(){ printf("pa_idxset_remove_by_index\n");}
int pa_idxset_rrobin(){ printf("pa_idxset_rrobin\n");}
int pa_idxset_size(){ printf("pa_idxset_size\n");}
int pa_idxset_steal_first(){ printf("pa_idxset_steal_first\n");}
int pa_idxset_string_compare_func(){ printf("pa_idxset_string_compare_func\n");}
int pa_idxset_string_hash_func(){ printf("pa_idxset_string_hash_func\n");}
int pa_idxset_trivial_compare_func(){ printf("pa_idxset_trivial_compare_func\n");}
int pa_idxset_trivial_hash_func(){ printf("pa_idxset_trivial_hash_func\n");}
int pa_in_system_mode(){ printf("pa_in_system_mode\n");}
/*int pa_init_i18n(){ printf("pa_init_i18n\n");} */
int pa_init_proplist(){ printf("pa_init_proplist\n");}
int pa_interleave(){ printf("pa_interleave\n");}
int pa_iochannel_creds_enable(){ printf("pa_iochannel_creds_enable\n");}
int pa_iochannel_creds_supported(){ printf("pa_iochannel_creds_supported\n");}
int pa_iochannel_free(){ printf("pa_iochannel_free\n");}
int pa_iochannel_get_mainloop_api(){ printf("pa_iochannel_get_mainloop_api\n");}
int pa_iochannel_get_recv_fd(){ printf("pa_iochannel_get_recv_fd\n");}
int pa_iochannel_get_send_fd(){ printf("pa_iochannel_get_send_fd\n");}
int pa_iochannel_is_hungup(){ printf("pa_iochannel_is_hungup\n");}
int pa_iochannel_is_readable(){ printf("pa_iochannel_is_readable\n");}
int pa_iochannel_is_writable(){ printf("pa_iochannel_is_writable\n");}
int pa_iochannel_new(){ printf("pa_iochannel_new\n");}
int pa_iochannel_read(){ printf("pa_iochannel_read\n");}
int pa_iochannel_read_with_creds(){ printf("pa_iochannel_read_with_creds\n");}
int pa_iochannel_set_callback(){ printf("pa_iochannel_set_callback\n");}
int pa_iochannel_set_noclose(){ printf("pa_iochannel_set_noclose\n");}
int pa_iochannel_socket_is_local(){ printf("pa_iochannel_socket_is_local\n");}
int pa_iochannel_socket_peer_to_string(){ printf("pa_iochannel_socket_peer_to_string\n");}
int pa_iochannel_socket_set_rcvbuf(){ printf("pa_iochannel_socket_set_rcvbuf\n");}
int pa_iochannel_socket_set_sndbuf(){ printf("pa_iochannel_socket_set_sndbuf\n");}
int pa_iochannel_write(){ printf("pa_iochannel_write\n");}
int pa_iochannel_write_with_creds(){ printf("pa_iochannel_write_with_creds\n");}
int pa_ioline_close(){ printf("pa_ioline_close\n");}
int pa_ioline_defer_close(){ printf("pa_ioline_defer_close\n");}
int pa_ioline_detach_iochannel(){ printf("pa_ioline_detach_iochannel\n");}
int pa_ioline_is_drained(){ printf("pa_ioline_is_drained\n");}
int pa_ioline_new(){ printf("pa_ioline_new\n");}
int pa_ioline_printf(){ printf("pa_ioline_printf\n");}
int pa_ioline_puts(){ printf("pa_ioline_puts\n");}
int pa_ioline_ref(){ printf("pa_ioline_ref\n");}
int pa_ioline_set_callback(){ printf("pa_ioline_set_callback\n");}
int pa_ioline_set_drain_callback(){ printf("pa_ioline_set_drain_callback\n");}
int pa_ioline_unref(){ printf("pa_ioline_unref\n");}
int pa_ip_acl_check(){ printf("pa_ip_acl_check\n");}
int pa_ip_acl_free(){ printf("pa_ip_acl_free\n");}
int pa_ip_acl_new(){ printf("pa_ip_acl_new\n");}
int pa_is_fd_nonblock(){ printf("pa_is_fd_nonblock\n");}
int pa_is_ip_address(){ printf("pa_is_ip_address\n");}
int pa_is_path_absolute(){ printf("pa_is_path_absolute\n");}
int pa_locale_to_utf8(){ printf("pa_locale_to_utf8\n");}
int pa_lock_fd(){ printf("pa_lock_fd\n");}
int pa_lock_lockfile(){ printf("pa_lock_lockfile\n");}
int pa_log_level(){ printf("pa_log_level\n");}
int pa_log_level_meta(){ printf("pa_log_level_meta\n");}
int pa_log_levelv(){ printf("pa_log_levelv\n");}
int pa_log_levelv_meta(){ printf("pa_log_levelv_meta\n");}
int pa_log_parse_target(){ printf("pa_log_parse_target\n");}
int pa_log_ratelimit(){ printf("pa_log_ratelimit\n");}
int pa_log_set_flags(){ printf("pa_log_set_flags\n");}
int pa_log_set_ident(){ printf("pa_log_set_ident\n");}
int pa_log_set_level(){ printf("pa_log_set_level\n");}
int pa_log_set_show_backtrace(){ printf("pa_log_set_show_backtrace\n");}
int pa_log_set_skip_backtrace(){ printf("pa_log_set_skip_backtrace\n");}
int pa_log_set_target(){ printf("pa_log_set_target\n");}
int pa_log_target_free(){ printf("pa_log_target_free\n");}
int pa_log_target_new(){ printf("pa_log_target_new\n");}
int pa_log_target_to_string(){ printf("pa_log_target_to_string\n");}
int pa_loop_read(){ printf("pa_loop_read\n");}
int pa_loop_write(){ printf("pa_loop_write\n");}
int pa_machine_id(){ printf("pa_machine_id\n");}
int pa_mainloop_api_once(){ printf("pa_mainloop_api_once\n");}
int pa_mainloop_dispatch(){ printf("pa_mainloop_dispatch\n");}
int pa_mainloop_free(){ printf("pa_mainloop_free\n");}
int pa_mainloop_get_api(){ printf("pa_mainloop_get_api\n");}
int pa_mainloop_get_retval(){ printf("pa_mainloop_get_retval\n");}
int pa_mainloop_iterate(){ printf("pa_mainloop_iterate\n");}
int pa_mainloop_new(){ printf("pa_mainloop_new\n");}
int pa_mainloop_poll(){ printf("pa_mainloop_poll\n");}
int pa_mainloop_prepare(){ printf("pa_mainloop_prepare\n");}
int pa_mainloop_quit(){ printf("pa_mainloop_quit\n");}
int pa_mainloop_run(){ printf("pa_mainloop_run\n");}
int pa_mainloop_set_poll_func(){ printf("pa_mainloop_set_poll_func\n");}
int pa_mainloop_wakeup(){ printf("pa_mainloop_wakeup\n");}
int pa_make_fd_block(){ printf("pa_make_fd_block\n");}
int pa_make_fd_cloexec(){ printf("pa_make_fd_cloexec\n");}
int pa_make_fd_nonblock(){ printf("pa_make_fd_nonblock\n");}
int pa_make_path_absolute(){ printf("pa_make_path_absolute\n");}
int pa_make_realtime(){ printf("pa_make_realtime\n");}
int pa_make_secure_dir(){ printf("pa_make_secure_dir\n");}
int pa_make_secure_parent_dir(){ printf("pa_make_secure_parent_dir\n");}
int pa_make_socket_low_delay(){ printf("pa_make_socket_low_delay\n");}
int pa_make_tcp_socket_low_delay(){ printf("pa_make_tcp_socket_low_delay\n");}
int pa_make_udp_socket_low_delay(){ printf("pa_make_udp_socket_low_delay\n");}
int pa_match(){ printf("pa_match\n");}
int pa_maybe_prefix_path(){ printf("pa_maybe_prefix_path\n");}
int pa_mcalign_csize(){ printf("pa_mcalign_csize\n");}
int pa_mcalign_flush(){ printf("pa_mcalign_flush\n");}
int pa_mcalign_free(){ printf("pa_mcalign_free\n");}
int pa_mcalign_new(){ printf("pa_mcalign_new\n");}
int pa_mcalign_pop(){ printf("pa_mcalign_pop\n");}
int pa_mcalign_push(){ printf("pa_mcalign_push\n");}
int pa_memblock_acquire(){ printf("pa_memblock_acquire\n");}
int pa_memblock_acquire_chunk(){ printf("pa_memblock_acquire_chunk\n");}
int pa_memblock_get_length(){ printf("pa_memblock_get_length\n");}
int pa_memblock_get_pool(){ printf("pa_memblock_get_pool\n");}
int pa_memblock_is_read_only(){ printf("pa_memblock_is_read_only\n");}
int pa_memblock_is_silence(){ printf("pa_memblock_is_silence\n");}
int pa_memblock_new(){ printf("pa_memblock_new\n");}
int pa_memblock_new_fixed(){ printf("pa_memblock_new_fixed\n");}
int pa_memblock_new_pool(){ printf("pa_memblock_new_pool\n");}
int pa_memblock_new_user(){ printf("pa_memblock_new_user\n");}
int pa_memblock_ref(){ printf("pa_memblock_ref\n");}
int pa_memblock_ref_is_one(){ printf("pa_memblock_ref_is_one\n");}
int pa_memblock_release(){ printf("pa_memblock_release\n");}
int pa_memblock_set_is_silence(){ printf("pa_memblock_set_is_silence\n");}
int pa_memblock_unref(){ printf("pa_memblock_unref\n");}
int pa_memblock_unref_fixed(){ printf("pa_memblock_unref_fixed\n");}
int pa_memblock_will_need(){ printf("pa_memblock_will_need\n");}
int pa_memblockq_apply_attr(){ printf("pa_memblockq_apply_attr\n");}
int pa_memblockq_drop(){ printf("pa_memblockq_drop\n");}
int pa_memblockq_flush_read(){ printf("pa_memblockq_flush_read\n");}
int pa_memblockq_flush_write(){ printf("pa_memblockq_flush_write\n");}
int pa_memblockq_free(){ printf("pa_memblockq_free\n");}
int pa_memblockq_get_attr(){ printf("pa_memblockq_get_attr\n");}
int pa_memblockq_get_base(){ printf("pa_memblockq_get_base\n");}
int pa_memblockq_get_length(){ printf("pa_memblockq_get_length\n");}
int pa_memblockq_get_maxlength(){ printf("pa_memblockq_get_maxlength\n");}
int pa_memblockq_get_maxrewind(){ printf("pa_memblockq_get_maxrewind\n");}
int pa_memblockq_get_minreq(){ printf("pa_memblockq_get_minreq\n");}
int pa_memblockq_get_nblocks(){ printf("pa_memblockq_get_nblocks\n");}
int pa_memblockq_get_prebuf(){ printf("pa_memblockq_get_prebuf\n");}
int pa_memblockq_get_read_index(){ printf("pa_memblockq_get_read_index\n");}
int pa_memblockq_get_tlength(){ printf("pa_memblockq_get_tlength\n");}
int pa_memblockq_get_write_index(){ printf("pa_memblockq_get_write_index\n");}
int pa_memblockq_is_empty(){ printf("pa_memblockq_is_empty\n");}
int pa_memblockq_is_readable(){ printf("pa_memblockq_is_readable\n");}
int pa_memblockq_missing(){ printf("pa_memblockq_missing\n");}
int pa_memblockq_new(){ printf("pa_memblockq_new\n");}
int pa_memblockq_peek(){ printf("pa_memblockq_peek\n");}
int pa_memblockq_peek_fixed_size(){ printf("pa_memblockq_peek_fixed_size\n");}
int pa_memblockq_pop_missing(){ printf("pa_memblockq_pop_missing\n");}
int pa_memblockq_prebuf_active(){ printf("pa_memblockq_prebuf_active\n");}
int pa_memblockq_prebuf_disable(){ printf("pa_memblockq_prebuf_disable\n");}
int pa_memblockq_prebuf_force(){ printf("pa_memblockq_prebuf_force\n");}
int pa_memblockq_push(){ printf("pa_memblockq_push\n");}
int pa_memblockq_push_align(){ printf("pa_memblockq_push_align\n");}
int pa_memblockq_rewind(){ printf("pa_memblockq_rewind\n");}
int pa_memblockq_seek(){ printf("pa_memblockq_seek\n");}
int pa_memblockq_set_maxlength(){ printf("pa_memblockq_set_maxlength\n");}
int pa_memblockq_set_maxrewind(){ printf("pa_memblockq_set_maxrewind\n");}
int pa_memblockq_set_minreq(){ printf("pa_memblockq_set_minreq\n");}
int pa_memblockq_set_prebuf(){ printf("pa_memblockq_set_prebuf\n");}
int pa_memblockq_set_silence(){ printf("pa_memblockq_set_silence\n");}
int pa_memblockq_set_tlength(){ printf("pa_memblockq_set_tlength\n");}
int pa_memblockq_silence(){ printf("pa_memblockq_silence\n");}
int pa_memblockq_splice(){ printf("pa_memblockq_splice\n");}
int pa_memblockq_willneed(){ printf("pa_memblockq_willneed\n");}
int pa_memchunk_dump_to_file(){ printf("pa_memchunk_dump_to_file\n");}
int pa_memchunk_isset(){ printf("pa_memchunk_isset\n");}
int pa_memchunk_make_writable(){ printf("pa_memchunk_make_writable\n");}
int pa_memchunk_memcpy(){ printf("pa_memchunk_memcpy\n");}
int pa_memchunk_reset(){ printf("pa_memchunk_reset\n");}
int pa_memchunk_sine(){ printf("pa_memchunk_sine\n");}
int pa_memchunk_will_need(){ printf("pa_memchunk_will_need\n");}
int pa_memexport_free(){ printf("pa_memexport_free\n");}
int pa_memexport_new(){ printf("pa_memexport_new\n");}
int pa_memexport_process_release(){ printf("pa_memexport_process_release\n");}
int pa_memexport_put(){ printf("pa_memexport_put\n");}
int pa_memimport_free(){ printf("pa_memimport_free\n");}
int pa_memimport_get(){ printf("pa_memimport_get\n");}
int pa_memimport_new(){ printf("pa_memimport_new\n");}
int pa_memimport_process_revoke(){ printf("pa_memimport_process_revoke\n");}
int pa_mempool_block_size_max(){ printf("pa_mempool_block_size_max\n");}
int pa_mempool_free(){ printf("pa_mempool_free\n");}
int pa_mempool_get_shm_id(){ printf("pa_mempool_get_shm_id\n");}
int pa_mempool_get_stat(){ printf("pa_mempool_get_stat\n");}
int pa_mempool_is_shared(){ printf("pa_mempool_is_shared\n");}
int pa_mempool_new(){ printf("pa_mempool_new\n");}
int pa_mempool_vacuum(){ printf("pa_mempool_vacuum\n");}
int pa_memtrap_add(){ printf("pa_memtrap_add\n");}
int pa_memtrap_install(){ printf("pa_memtrap_install\n");}
int pa_memtrap_is_good(){ printf("pa_memtrap_is_good\n");}
int pa_memtrap_remove(){ printf("pa_memtrap_remove\n");}
int pa_memtrap_update(){ printf("pa_memtrap_update\n");}
int pa_msleep(){ printf("pa_msleep\n");}
int pa_mutex_free(){ printf("pa_mutex_free\n");}
int pa_mutex_lock(){ printf("pa_mutex_lock\n");}
int pa_mutex_new(){ printf("pa_mutex_new\n");}
int pa_mutex_try_lock(){ printf("pa_mutex_try_lock\n");}
int pa_mutex_unlock(){ printf("pa_mutex_unlock\n");}
int pa_ncpus(){ printf("pa_ncpus\n");}
int pa_nullify_stdfds(){ printf("pa_nullify_stdfds\n");}
int pa_once_begin(){ printf("pa_once_begin\n");}
int pa_once_end(){ printf("pa_once_end\n");}
int pa_open_cloexec(){ printf("pa_open_cloexec\n");}
int pa_open_config_file(){ printf("pa_open_config_file\n");}
int pa_operation_cancel(){ printf("pa_operation_cancel\n");}
/*int pa_operation_get_state(){ printf("pa_operation_get_state\n");}*/
int pa_operation_ref(){ printf("pa_operation_ref\n");}
int pa_operation_set_state_callback(){ printf("pa_operation_set_state_callback\n");}
/*int pa_operation_unref(){ printf("pa_operation_unref\n");}*/
int pa_own_uid_in_group(){ printf("pa_own_uid_in_group\n");}
int pa_packet_new(){ printf("pa_packet_new\n");}
int pa_packet_new_dynamic(){ printf("pa_packet_new_dynamic\n");}
int pa_packet_ref(){ printf("pa_packet_ref\n");}
int pa_packet_unref(){ printf("pa_packet_unref\n");}
int pa_parent_dir(){ printf("pa_parent_dir\n");}
int pa_parse_address(){ printf("pa_parse_address\n");}
int pa_parse_boolean(){ printf("pa_parse_boolean\n");}
int pa_parse_sample_format(){ printf("pa_parse_sample_format\n");}
int pa_parse_volume(){ printf("pa_parse_volume\n");}
int pa_parsehex(){ printf("pa_parsehex\n");}
int pa_path_get_filename(){ printf("pa_path_get_filename\n");}
int pa_pdispatch_creds(){ printf("pa_pdispatch_creds\n");}
int pa_pdispatch_is_pending(){ printf("pa_pdispatch_is_pending\n");}
int pa_pdispatch_new(){ printf("pa_pdispatch_new\n");}
int pa_pdispatch_ref(){ printf("pa_pdispatch_ref\n");}
int pa_pdispatch_register_reply(){ printf("pa_pdispatch_register_reply\n");}
int pa_pdispatch_run(){ printf("pa_pdispatch_run\n");}
int pa_pdispatch_set_drain_callback(){ printf("pa_pdispatch_set_drain_callback\n");}
int pa_pdispatch_unref(){ printf("pa_pdispatch_unref\n");}
int pa_pdispatch_unregister_reply(){ printf("pa_pdispatch_unregister_reply\n");}
int pa_pid_file_check_running(){ printf("pa_pid_file_check_running\n");}
int pa_pid_file_create(){ printf("pa_pid_file_create\n");}
int pa_pid_file_kill(){ printf("pa_pid_file_kill\n");}
int pa_pid_file_remove(){ printf("pa_pid_file_remove\n");}
int pa_pipe_buf(){ printf("pa_pipe_buf\n");}
int pa_pipe_cloexec(){ printf("pa_pipe_cloexec\n");}
int pa_proplist_clear(){ printf("pa_proplist_clear\n");}
int pa_proplist_contains(){ printf("pa_proplist_contains\n");}
int pa_proplist_copy(){ printf("pa_proplist_copy\n");}
int pa_proplist_equal(){ printf("pa_proplist_equal\n");}
int pa_proplist_free(){ printf("pa_proplist_free\n");}
int pa_proplist_from_string(){ printf("pa_proplist_from_string\n");}
int pa_proplist_get(){ printf("pa_proplist_get\n");}
int pa_proplist_get_stream_group(){ printf("pa_proplist_get_stream_group\n");}
int pa_proplist_gets(){ printf("pa_proplist_gets\n");}
int pa_proplist_isempty(){ printf("pa_proplist_isempty\n");}
int pa_proplist_iterate(){ printf("pa_proplist_iterate\n");}
int pa_proplist_key_valid(){ printf("pa_proplist_key_valid\n");}
int pa_proplist_new(){ printf("pa_proplist_new\n");}
int pa_proplist_set(){ printf("pa_proplist_set\n");}
int pa_proplist_setf(){ printf("pa_proplist_setf\n");}
int pa_proplist_setp(){ printf("pa_proplist_setp\n");}
int pa_proplist_sets(){ printf("pa_proplist_sets\n");}
int pa_proplist_size(){ printf("pa_proplist_size\n");}
int pa_proplist_to_string(){ printf("pa_proplist_to_string\n");}
int pa_proplist_to_string_sep(){ printf("pa_proplist_to_string_sep\n");}
int pa_proplist_unset(){ printf("pa_proplist_unset\n");}
int pa_proplist_unset_many(){ printf("pa_proplist_unset_many\n");}
int pa_proplist_update(){ printf("pa_proplist_update\n");}
int pa_pstream_enable_shm(){ printf("pa_pstream_enable_shm\n");}
int pa_pstream_get_shm(){ printf("pa_pstream_get_shm\n");}
int pa_pstream_is_pending(){ printf("pa_pstream_is_pending\n");}
int pa_pstream_new(){ printf("pa_pstream_new\n");}
int pa_pstream_ref(){ printf("pa_pstream_ref\n");}
int pa_pstream_send_error(){ printf("pa_pstream_send_error\n");}
int pa_pstream_send_memblock(){ printf("pa_pstream_send_memblock\n");}
int pa_pstream_send_packet(){ printf("pa_pstream_send_packet\n");}
int pa_pstream_send_release(){ printf("pa_pstream_send_release\n");}
int pa_pstream_send_revoke(){ printf("pa_pstream_send_revoke\n");}
int pa_pstream_send_simple_ack(){ printf("pa_pstream_send_simple_ack\n");}
int pa_pstream_send_tagstruct_with_creds(){ printf("pa_pstream_send_tagstruct_with_creds\n");}
int pa_pstream_set_die_callback(){ printf("pa_pstream_set_die_callback\n");}
int pa_pstream_set_drain_callback(){ printf("pa_pstream_set_drain_callback\n");}
int pa_pstream_set_receive_memblock_callback(){ printf("pa_pstream_set_receive_memblock_callback\n");}
int pa_pstream_set_receive_packet_callback(){ printf("pa_pstream_set_receive_packet_callback\n");}
int pa_pstream_set_release_callback(){ printf("pa_pstream_set_release_callback\n");}
int pa_pstream_set_revoke_callback(){ printf("pa_pstream_set_revoke_callback\n");}
int pa_pstream_unlink(){ printf("pa_pstream_unlink\n");}
int pa_pstream_unref(){ printf("pa_pstream_unref\n");}
int pa_queue_free(){ printf("pa_queue_free\n");}
int pa_queue_isempty(){ printf("pa_queue_isempty\n");}
int pa_queue_new(){ printf("pa_queue_new\n");}
int pa_queue_pop(){ printf("pa_queue_pop\n");}
int pa_queue_push(){ printf("pa_queue_push\n");}
int pa_raise_priority(){ printf("pa_raise_priority\n");}
int pa_random(){ printf("pa_random\n");}
int pa_random_seed(){ printf("pa_random_seed\n");}
int pa_ratelimit_test(){ printf("pa_ratelimit_test\n");}
int pa_read(){ printf("pa_read\n");}
int pa_read_line_from_file(){ printf("pa_read_line_from_file\n");}
int pa_readlink(){ printf("pa_readlink\n");}
int pa_realpath(){ printf("pa_realpath\n");}
int pa_reduce(){ printf("pa_reduce\n");}
int pa_replace(){ printf("pa_replace\n");}
int pa_reset_personality(){ printf("pa_reset_personality\n");}
int pa_reset_priority(){ printf("pa_reset_priority\n");}
int pa_reset_sigs(){ printf("pa_reset_sigs\n");}
int pa_reset_sigsv(){ printf("pa_reset_sigsv\n");}
int pa_rtclock_age(){ printf("pa_rtclock_age\n");}
int pa_rtclock_from_wallclock(){ printf("pa_rtclock_from_wallclock\n");}
int pa_rtclock_get(){ printf("pa_rtclock_get\n");}
int pa_rtclock_hrtimer(){ printf("pa_rtclock_hrtimer\n");}
int pa_rtclock_hrtimer_enable(){ printf("pa_rtclock_hrtimer_enable\n");}
int pa_rtclock_now(){ printf("pa_rtclock_now\n");}
int pa_run_from_build_tree(){ printf("pa_run_from_build_tree\n");}
int pa_run_once(){ printf("pa_run_once\n");}
int pa_running_in_vm(){ printf("pa_running_in_vm\n");}
int pa_runtime_path(){ printf("pa_runtime_path\n");}
int pa_sample_clamp(){ printf("pa_sample_clamp\n");}
int pa_sample_format_is_be(){ printf("pa_sample_format_is_be\n");}
int pa_sample_format_is_le(){ printf("pa_sample_format_is_le\n");}
/*int pa_sample_format_to_string(){ printf("pa_sample_format_to_string\n");}*/
int pa_sample_format_valid(){ printf("pa_sample_format_valid\n");}
int pa_sample_rate_valid(){ printf("pa_sample_rate_valid\n");}
int pa_sample_size(){ printf("pa_sample_size\n");}
int pa_sample_size_of_format(){ printf("pa_sample_size_of_format\n");}
int pa_sample_spec_equal(){ printf("pa_sample_spec_equal\n");}
int pa_sample_spec_init(){ printf("pa_sample_spec_init\n");}
/*int pa_sample_spec_snprint(){ printf("pa_sample_spec_snprint\n");}*/
/*int pa_sample_spec_valid(){ printf("pa_sample_spec_valid\n");}*/
int pa_semaphore_free(){ printf("pa_semaphore_free\n");}
int pa_semaphore_new(){ printf("pa_semaphore_new\n");}
int pa_semaphore_post(){ printf("pa_semaphore_post\n");}
int pa_semaphore_wait(){ printf("pa_semaphore_wait\n");}
int pa_session_id(){ printf("pa_session_id\n");}
int pa_set_env(){ printf("pa_set_env\n");}
int pa_set_env_and_record(){ printf("pa_set_env_and_record\n");}
int pa_set_volume_func(){ printf("pa_set_volume_func\n");}
int pa_shm_attach_ro(){ printf("pa_shm_attach_ro\n");}
int pa_shm_cleanup(){ printf("pa_shm_cleanup\n");}
int pa_shm_create_rw(){ printf("pa_shm_create_rw\n");}
int pa_shm_free(){ printf("pa_shm_free\n");}
int pa_shm_punch(){ printf("pa_shm_punch\n");}
int pa_sig2str(){ printf("pa_sig2str\n");}
int pa_signal_done(){ printf("pa_signal_done\n");}
int pa_signal_free(){ printf("pa_signal_free\n");}
int pa_signal_init(){ printf("pa_signal_init\n");}
int pa_signal_new(){ printf("pa_signal_new\n");}
int pa_signal_set_destroy(){ printf("pa_signal_set_destroy\n");}
int pa_silence_cache_done(){ printf("pa_silence_cache_done\n");}
int pa_silence_cache_init(){ printf("pa_silence_cache_init\n");}
int pa_silence_memblock(){ printf("pa_silence_memblock\n");}
int pa_silence_memchunk(){ printf("pa_silence_memchunk\n");}
int pa_silence_memchunk_get(){ printf("pa_silence_memchunk_get\n");}
int pa_silence_memory(){ printf("pa_silence_memory\n");}
int pa_smoother_fix_now(){ printf("pa_smoother_fix_now\n");}
int pa_smoother_free(){ printf("pa_smoother_free\n");}
int pa_smoother_get(){ printf("pa_smoother_get\n");}
int pa_smoother_new(){ printf("pa_smoother_new\n");}
int pa_smoother_pause(){ printf("pa_smoother_pause\n");}
int pa_smoother_put(){ printf("pa_smoother_put\n");}
int pa_smoother_reset(){ printf("pa_smoother_reset\n");}
int pa_smoother_resume(){ printf("pa_smoother_resume\n");}
int pa_smoother_set_time_offset(){ printf("pa_smoother_set_time_offset\n");}
int pa_smoother_translate(){ printf("pa_smoother_translate\n");}
int pa_sndfile_dump_formats(){ printf("pa_sndfile_dump_formats\n");}
int pa_sndfile_format_from_string(){ printf("pa_sndfile_format_from_string\n");}
int pa_sndfile_init_proplist(){ printf("pa_sndfile_init_proplist\n");}
int pa_sndfile_read_channel_map(){ printf("pa_sndfile_read_channel_map\n");}
int pa_sndfile_read_sample_spec(){ printf("pa_sndfile_read_sample_spec\n");}
int pa_sndfile_readf_function(){ printf("pa_sndfile_readf_function\n");}
int pa_sndfile_write_channel_map(){ printf("pa_sndfile_write_channel_map\n");}
int pa_sndfile_write_sample_spec(){ printf("pa_sndfile_write_sample_spec\n");}
int pa_sndfile_writef_function(){ printf("pa_sndfile_writef_function\n");}
int pa_snprintf(){ printf("pa_snprintf\n");}
int pa_socket_address_is_local(){ printf("pa_socket_address_is_local\n");}
int pa_socket_client_is_local(){ printf("pa_socket_client_is_local\n");}
int pa_socket_client_new_ipv4(){ printf("pa_socket_client_new_ipv4\n");}
int pa_socket_client_new_ipv6(){ printf("pa_socket_client_new_ipv6\n");}
int pa_socket_client_new_sockaddr(){ printf("pa_socket_client_new_sockaddr\n");}
int pa_socket_client_new_string(){ printf("pa_socket_client_new_string\n");}
int pa_socket_client_new_unix(){ printf("pa_socket_client_new_unix\n");}
int pa_socket_client_ref(){ printf("pa_socket_client_ref\n");}
int pa_socket_client_set_callback(){ printf("pa_socket_client_set_callback\n");}
int pa_socket_client_unref(){ printf("pa_socket_client_unref\n");}
int pa_socket_cloexec(){ printf("pa_socket_cloexec\n");}
int pa_socket_is_local(){ printf("pa_socket_is_local\n");}
int pa_socket_peer_to_string(){ printf("pa_socket_peer_to_string\n");}
int pa_socket_server_get_address(){ printf("pa_socket_server_get_address\n");}
int pa_socket_server_new(){ printf("pa_socket_server_new\n");}
int pa_socket_server_new_ipv4(){ printf("pa_socket_server_new_ipv4\n");}
int pa_socket_server_new_ipv4_any(){ printf("pa_socket_server_new_ipv4_any\n");}
int pa_socket_server_new_ipv4_loopback(){ printf("pa_socket_server_new_ipv4_loopback\n");}
int pa_socket_server_new_ipv4_string(){ printf("pa_socket_server_new_ipv4_string\n");}
int pa_socket_server_new_ipv6(){ printf("pa_socket_server_new_ipv6\n");}
int pa_socket_server_new_ipv6_any(){ printf("pa_socket_server_new_ipv6_any\n");}
int pa_socket_server_new_ipv6_loopback(){ printf("pa_socket_server_new_ipv6_loopback\n");}
int pa_socket_server_new_ipv6_string(){ printf("pa_socket_server_new_ipv6_string\n");}
int pa_socket_server_new_unix(){ printf("pa_socket_server_new_unix\n");}
int pa_socket_server_ref(){ printf("pa_socket_server_ref\n");}
int pa_socket_server_set_callback(){ printf("pa_socket_server_set_callback\n");}
int pa_socket_server_unref(){ printf("pa_socket_server_unref\n");}
int pa_socket_set_rcvbuf(){ printf("pa_socket_set_rcvbuf\n");}
int pa_socket_set_sndbuf(){ printf("pa_socket_set_sndbuf\n");}
int pa_split(){ printf("pa_split\n");}
int pa_split_in_place(){ printf("pa_split_in_place\n");}
int pa_split_spaces(){ printf("pa_split_spaces\n");}
int pa_split_spaces_strv(){ printf("pa_split_spaces_strv\n");}
int pa_sprintf_malloc(){ printf("pa_sprintf_malloc\n");}
int pa_startswith(){ printf("pa_startswith\n");}
int pa_state_path(){ printf("pa_state_path\n");}
int pa_static_mutex_get(){ printf("pa_static_mutex_get\n");}
int pa_static_semaphore_get(){ printf("pa_static_semaphore_get\n");}
int pa_str_in_list_spaces(){ printf("pa_str_in_list_spaces\n");}
int pa_strbuf_free(){ printf("pa_strbuf_free\n");}
int pa_strbuf_isempty(){ printf("pa_strbuf_isempty\n");}
int pa_strbuf_new(){ printf("pa_strbuf_new\n");}
int pa_strbuf_printf(){ printf("pa_strbuf_printf\n");}
int pa_strbuf_putc(){ printf("pa_strbuf_putc\n");}
int pa_strbuf_puts(){ printf("pa_strbuf_puts\n");}
int pa_strbuf_putsn(){ printf("pa_strbuf_putsn\n");}
int pa_strbuf_tostring(){ printf("pa_strbuf_tostring\n");}
int pa_strbuf_tostring_free(){ printf("pa_strbuf_tostring_free\n");}
int pa_stream_begin_write(){ printf("pa_stream_begin_write\n");}
int pa_stream_cancel_write(){ printf("pa_stream_cancel_write\n");}
/* int pa_stream_connect_playback(){ printf("pa_stream_connect_playback\n");} */
/*int pa_stream_connect_record(){ printf("pa_stream_connect_record\n");}*/
int pa_stream_connect_upload(){ printf("pa_stream_connect_upload\n");}
/*int pa_stream_cork(){ printf("pa_stream_cork\n");}*/
/*int pa_stream_disconnect(){ printf("pa_stream_disconnect\n");}*/
int pa_stream_drain(){ printf("pa_stream_drain\n");}
int pa_stream_drop(){ printf("pa_stream_drop\n");}
int pa_stream_finish_upload(){ printf("pa_stream_finish_upload\n");}
int pa_stream_flush(){ printf("pa_stream_flush\n");}
/*int pa_stream_get_buffer_attr(){ printf("pa_stream_get_buffer_attr\n");}*/
int pa_stream_get_channel_map(){ printf("pa_stream_get_channel_map\n");}
int pa_stream_get_context(){ printf("pa_stream_get_context\n");}
int pa_stream_get_device_index(){ printf("pa_stream_get_device_index\n");}
int pa_stream_get_device_name(){ printf("pa_stream_get_device_name\n");}
int pa_stream_get_format_info(){ printf("pa_stream_get_format_info\n");}
int pa_stream_get_index(){ printf("pa_stream_get_index\n");}
int pa_stream_get_latency(){ printf("pa_stream_get_latency\n");}
int pa_stream_get_monitor_stream(){ printf("pa_stream_get_monitor_stream\n");}
/*int pa_stream_get_sample_spec(){ printf("pa_stream_get_sample_spec\n");}*/
/*int pa_stream_get_state(){ printf("pa_stream_get_state\n");}*/
int pa_stream_get_time(){ printf("pa_stream_get_time\n");}
int pa_stream_get_timing_info(){ printf("pa_stream_get_timing_info\n");}
int pa_stream_get_underflow_index(){ printf("pa_stream_get_underflow_index\n");}
int pa_stream_is_corked(){ printf("pa_stream_is_corked\n");}
int pa_stream_is_suspended(){ printf("pa_stream_is_suspended\n");}
/*int pa_stream_new(){ printf("pa_stream_new\n");}*/
int pa_stream_new_extended(){ printf("pa_stream_new_extended\n");}
int pa_stream_new_with_proplist(){ printf("pa_stream_new_with_proplist\n");}
/*int pa_stream_peek(){ printf("pa_stream_peek\n");}*/
int pa_stream_prebuf(){ printf("pa_stream_prebuf\n");}
int pa_stream_proplist_remove(){ printf("pa_stream_proplist_remove\n");}
int pa_stream_proplist_update(){ printf("pa_stream_proplist_update\n");}
int pa_stream_readable_size(){ printf("pa_stream_readable_size\n");}
int pa_stream_ref(){ printf("pa_stream_ref\n");}
int pa_stream_set_buffer_attr(){ printf("pa_stream_set_buffer_attr\n");}
int pa_stream_set_buffer_attr_callback(){ printf("pa_stream_set_buffer_attr_callback\n");}
int pa_stream_set_event_callback(){ printf("pa_stream_set_event_callback\n");}
int pa_stream_set_latency_update_callback(){ printf("pa_stream_set_latency_update_callback\n");}
int pa_stream_set_monitor_stream(){ printf("pa_stream_set_monitor_stream\n");}
int pa_stream_set_moved_callback(){ printf("pa_stream_set_moved_callback\n");}
int pa_stream_set_name(){ printf("pa_stream_set_name\n");}
int pa_stream_set_overflow_callback(){ printf("pa_stream_set_overflow_callback\n");}
/*int pa_stream_set_read_callback(){ printf("pa_stream_set_read_callback\n");}*/
int pa_stream_set_started_callback(){ printf("pa_stream_set_started_callback\n");}
/*int pa_stream_set_state_callback(){ printf("pa_stream_set_state_callback\n");}*/
int pa_stream_set_suspended_callback(){ printf("pa_stream_set_suspended_callback\n");}
/*int pa_stream_set_underflow_callback(){ printf("pa_stream_set_underflow_callback\n");}*/
/*int pa_stream_set_write_callback(){ printf("pa_stream_set_write_callback\n");}*/
/*int pa_stream_trigger(){ printf("pa_stream_trigger\n");}*/
/*int pa_stream_unref(){ printf("pa_stream_unref\n");}*/
int pa_stream_update_sample_rate(){ printf("pa_stream_update_sample_rate\n");}
int pa_stream_update_timing_info(){ printf("pa_stream_update_timing_info\n");}
int pa_stream_writable_size(){ printf("pa_stream_writable_size\n");}
/*int pa_stream_write(){ printf("pa_stream_write\n");}*/
int pa_strerror(){ printf("pa_strerror\n");}
int pa_strip(){ printf("pa_strip\n");}
int pa_strip_nl(){ printf("pa_strip_nl\n");}
int pa_strlcpy(){ printf("pa_strlcpy\n");}
int pa_strlist_data(){ printf("pa_strlist_data\n");}
int pa_strlist_free(){ printf("pa_strlist_free\n");}
int pa_strlist_next(){ printf("pa_strlist_next\n");}
int pa_strlist_parse(){ printf("pa_strlist_parse\n");}
int pa_strlist_pop(){ printf("pa_strlist_pop\n");}
int pa_strlist_prepend(){ printf("pa_strlist_prepend\n");}
int pa_strlist_remove(){ printf("pa_strlist_remove\n");}
int pa_strlist_reverse(){ printf("pa_strlist_reverse\n");}
int pa_strlist_tostring(){ printf("pa_strlist_tostring\n");}
int pa_sw_cvolume_divide(){ printf("pa_sw_cvolume_divide\n");}
int pa_sw_cvolume_divide_scalar(){ printf("pa_sw_cvolume_divide_scalar\n");}
int pa_sw_cvolume_multiply(){ printf("pa_sw_cvolume_multiply\n");}
int pa_sw_cvolume_multiply_scalar(){ printf("pa_sw_cvolume_multiply_scalar\n");}
int pa_sw_cvolume_snprint_dB(){ printf("pa_sw_cvolume_snprint_dB\n");}
int pa_sw_volume_divide(){ printf("pa_sw_volume_divide\n");}
int pa_sw_volume_from_dB(){ printf("pa_sw_volume_from_dB\n");}
int pa_sw_volume_from_linear(){ printf("pa_sw_volume_from_linear\n");}
int pa_sw_volume_multiply(){ printf("pa_sw_volume_multiply\n");}
int pa_sw_volume_snprint_dB(){ printf("pa_sw_volume_snprint_dB\n");}
int pa_sw_volume_to_dB(){ printf("pa_sw_volume_to_dB\n");}
int pa_sw_volume_to_linear(){ printf("pa_sw_volume_to_linear\n");}
int pa_tagstruct_data(){ printf("pa_tagstruct_data\n");}
int pa_tagstruct_eof(){ printf("pa_tagstruct_eof\n");}
int pa_tagstruct_free(){ printf("pa_tagstruct_free\n");}
int pa_tagstruct_free_data(){ printf("pa_tagstruct_free_data\n");}
int pa_tagstruct_get(){ printf("pa_tagstruct_get\n");}
int pa_tagstruct_get_arbitrary(){ printf("pa_tagstruct_get_arbitrary\n");}
int pa_tagstruct_get_boolean(){ printf("pa_tagstruct_get_boolean\n");}
int pa_tagstruct_get_channel_map(){ printf("pa_tagstruct_get_channel_map\n");}
int pa_tagstruct_get_cvolume(){ printf("pa_tagstruct_get_cvolume\n");}
int pa_tagstruct_get_format_info(){ printf("pa_tagstruct_get_format_info\n");}
int pa_tagstruct_get_proplist(){ printf("pa_tagstruct_get_proplist\n");}
int pa_tagstruct_get_sample_spec(){ printf("pa_tagstruct_get_sample_spec\n");}
int pa_tagstruct_get_timeval(){ printf("pa_tagstruct_get_timeval\n");}
int pa_tagstruct_get_usec(){ printf("pa_tagstruct_get_usec\n");}
int pa_tagstruct_get_volume(){ printf("pa_tagstruct_get_volume\n");}
int pa_tagstruct_gets(){ printf("pa_tagstruct_gets\n");}
int pa_tagstruct_gets64(){ printf("pa_tagstruct_gets64\n");}
int pa_tagstruct_getu32(){ printf("pa_tagstruct_getu32\n");}
int pa_tagstruct_getu64(){ printf("pa_tagstruct_getu64\n");}
int pa_tagstruct_getu8(){ printf("pa_tagstruct_getu8\n");}
int pa_tagstruct_new(){ printf("pa_tagstruct_new\n");}
int pa_tagstruct_put(){ printf("pa_tagstruct_put\n");}
int pa_tagstruct_put_arbitrary(){ printf("pa_tagstruct_put_arbitrary\n");}
int pa_tagstruct_put_boolean(){ printf("pa_tagstruct_put_boolean\n");}
int pa_tagstruct_put_channel_map(){ printf("pa_tagstruct_put_channel_map\n");}
int pa_tagstruct_put_cvolume(){ printf("pa_tagstruct_put_cvolume\n");}
int pa_tagstruct_put_format_info(){ printf("pa_tagstruct_put_format_info\n");}
int pa_tagstruct_put_proplist(){ printf("pa_tagstruct_put_proplist\n");}
int pa_tagstruct_put_sample_spec(){ printf("pa_tagstruct_put_sample_spec\n");}
int pa_tagstruct_put_timeval(){ printf("pa_tagstruct_put_timeval\n");}
int pa_tagstruct_put_usec(){ printf("pa_tagstruct_put_usec\n");}
int pa_tagstruct_put_volume(){ printf("pa_tagstruct_put_volume\n");}
int pa_tagstruct_puts(){ printf("pa_tagstruct_puts\n");}
int pa_tagstruct_puts64(){ printf("pa_tagstruct_puts64\n");}
int pa_tagstruct_putu32(){ printf("pa_tagstruct_putu32\n");}
int pa_tagstruct_putu64(){ printf("pa_tagstruct_putu64\n");}
int pa_tagstruct_putu8(){ printf("pa_tagstruct_putu8\n");}
int pa_thread_free(){ printf("pa_thread_free\n");}
int pa_thread_free_nojoin(){ printf("pa_thread_free_nojoin\n");}
int pa_thread_get_data(){ printf("pa_thread_get_data\n");}
int pa_thread_get_name(){ printf("pa_thread_get_name\n");}
int pa_thread_is_running(){ printf("pa_thread_is_running\n");}
int pa_thread_join(){ printf("pa_thread_join\n");}
int pa_thread_new(){ printf("pa_thread_new\n");}
int pa_thread_self(){ printf("pa_thread_self\n");}
int pa_thread_set_data(){ printf("pa_thread_set_data\n");}
int pa_thread_set_name(){ printf("pa_thread_set_name\n");}
int pa_thread_yield(){ printf("pa_thread_yield\n");}
int pa_threaded_mainloop_accept(){ printf("pa_threaded_mainloop_accept\n");}
int pa_threaded_mainloop_free(){ printf("pa_threaded_mainloop_free\n");}
/*int pa_threaded_mainloop_get_api(){ printf("pa_threaded_mainloop_get_api\n");} */
int pa_threaded_mainloop_get_retval(){ printf("pa_threaded_mainloop_get_retval\n");}
/*int pa_threaded_mainloop_in_thread(){ printf("pa_threaded_mainloop_in_thread\n");}*/
/*int pa_threaded_mainloop_lock(){ printf("pa_threaded_mainloop_lock\n");}*/
/*int pa_threaded_mainloop_new(){ printf("pa_threaded_mainloop_new\n");}*/
int pa_threaded_mainloop_set_name(){ printf("pa_threaded_mainloop_set_name\n");}
/*int pa_threaded_mainloop_signal(){ printf("pa_threaded_mainloop_signal\n");}*/
/*int pa_threaded_mainloop_start(){ printf("pa_threaded_mainloop_start\n");}*/
int pa_threaded_mainloop_stop(){ printf("pa_threaded_mainloop_stop\n");}
/*int pa_threaded_mainloop_unlock(){ printf("pa_threaded_mainloop_unlock\n");}*/
/*int pa_threaded_mainloop_wait(){ printf("pa_threaded_mainloop_wait\n");}*/
int pa_timespec_load(){ printf("pa_timespec_load\n");}
int pa_timespec_store(){ printf("pa_timespec_store\n");}
int pa_timeval_add(){ printf("pa_timeval_add\n");}
int pa_timeval_age(){ printf("pa_timeval_age\n");}
int pa_timeval_cmp(){ printf("pa_timeval_cmp\n");}
int pa_timeval_diff(){ printf("pa_timeval_diff\n");}
int pa_timeval_load(){ printf("pa_timeval_load\n");}
int pa_timeval_rtstore(){ printf("pa_timeval_rtstore\n");}
int pa_timeval_store(){ printf("pa_timeval_store\n");}
int pa_timeval_sub(){ printf("pa_timeval_sub\n");}
int pa_tls_free(){ printf("pa_tls_free\n");}
int pa_tls_get(){ printf("pa_tls_get\n");}
int pa_tls_new(){ printf("pa_tls_new\n");}
int pa_tls_set(){ printf("pa_tls_set\n");}
int pa_tokenizer_free(){ printf("pa_tokenizer_free\n");}
int pa_tokenizer_get(){ printf("pa_tokenizer_get\n");}
int pa_tokenizer_new(){ printf("pa_tokenizer_new\n");}
int pa_truncate_utf8(){ printf("pa_truncate_utf8\n");}
int pa_uid_in_group(){ printf("pa_uid_in_group\n");}
int pa_uname_string(){ printf("pa_uname_string\n");}
int pa_unblock_sigs(){ printf("pa_unblock_sigs\n");}
int pa_unblock_sigsv(){ printf("pa_unblock_sigsv\n");}
int pa_unescape(){ printf("pa_unescape\n");}
int pa_unix_socket_is_stale(){ printf("pa_unix_socket_is_stale\n");}
int pa_unix_socket_remove_stale(){ printf("pa_unix_socket_remove_stale\n");}
int pa_unlock_lockfile(){ printf("pa_unlock_lockfile\n");}
int pa_unset_env_recorded(){ printf("pa_unset_env_recorded\n");}
/*int pa_usec_to_bytes(){ printf("pa_usec_to_bytes\n");}*/
int pa_usec_to_bytes_round_up(){ printf("pa_usec_to_bytes_round_up\n");}
int pa_utf8_filter(){ printf("pa_utf8_filter\n");}
int pa_utf8_to_locale(){ printf("pa_utf8_to_locale\n");}
int pa_utf8_valid(){ printf("pa_utf8_valid\n");}
int pa_volume_func_init_arm(){ printf("pa_volume_func_init_arm\n");}
int pa_volume_func_init_mmx(){ printf("pa_volume_func_init_mmx\n");}
int pa_volume_func_init_sse(){ printf("pa_volume_func_init_sse\n");}
int pa_volume_snprint(){ printf("pa_volume_snprint\n");}
int pa_volume_snprint_verbose(){ printf("pa_volume_snprint_verbose\n");}
int pa_vsnprintf(){ printf("pa_vsnprintf\n");}
int pa_vsprintf_malloc(){ printf("pa_vsprintf_malloc\n");}
int pa_will_need(){ printf("pa_will_need\n");}
int pa_write(){ printf("pa_write\n");}
int pa_x11_del_prop(){ printf("pa_x11_del_prop\n");}
int pa_x11_get_prop(){ printf("pa_x11_get_prop\n");}
int pa_x11_set_prop(){ printf("pa_x11_set_prop\n");}
int pa_xfree(){ printf("pa_xfree\n");}
int pa_xfreev(){ printf("pa_xfreev\n");}
int pa_xmalloc(){ printf("pa_xmalloc\n");}
int pa_xmalloc0(){ printf("pa_xmalloc0\n");}
int pa_xmemdup(){ printf("pa_xmemdup\n");}
int pa_xrealloc(){ printf("pa_xrealloc\n");}
int pa_xstrdup(){ printf("pa_xstrdup\n");}


#define log printf

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


static int context = 2;

int* pa_context_new  (  pa_mainloop_api *   mainloop, const char *    name  ){
    log("pa_context_new: mainloop_api=%p  and name=%s\n", mainloop, name); 
    return &context;
}

int* pa_context_drain(int *c, pa_context_notify_cb_t cb, void *userdata){
    log("pa_context_drain: not implemented\n");
    return NULL;
}

int mainloop=1;

int* pa_threaded_mainloop_new  (void){
    log("pa_threaded_mainloop_new: Faking new mainloop\n");
    return &mainloop;
}

why_buffer* why_buffer_new(size_t size){
    why_buffer* b = (why_buffer*)malloc(sizeof(why_buffer));
    b->buffer = (char*)malloc(size);
    //b->head = 0;
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

int stream1 = 6;

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
    log("Reporting valid specification(pa_sample_spec_valid)\n");
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


char* pa_sample_spec_snprint(char * s,  size_t l, const pa_sample_spec * spec){
    log("sample spec print %p %zu %p  \n", s, l, spec);
 /*   assert(s);
    assert(l > 0);
    assert(spec);*/
    //static char s1[1000];
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
}

static void *oss_thread_function(void *s1){
    stream_t* s = s1;
    char data[5120000];
    size_t n_data;
    while(s->running){
        if(s->read_callback){
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
    //why_buffer_delete(s->buffer);
    log("exiting oss thread\n");
}


int pa_stream_peek(stream_t *s, const void **data,	size_t *nbytes){
    static char g_data[10240];
    log("pa_stream_peek: ");
    *nbytes = read(s->fd, g_data, 10240);
    *data = g_data;
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
    log("pa_stream_write: nbytes=%llu   free_cb=%p   offset=%d seek_mode=%d \n", nbytes, free_cb, offset, seek);
    why_buffer_write(s->buffer, (char*)data, nbytes);
    return 0;
}

int* pa_stream_trigger(stream_t* s, pa_stream_success_cb_t cb, void *userdata){
    log("pa_stream_trigger: nothing to do\n");
    in_thread = 1;
    cb(s, 1, userdata);
    in_thread = 0;
}


const pa_buffer_attr* pa_stream_get_buffer_attr(stream_t *s){
    log("pa_stream_get_buffer_attr: returning buffer attributes\n");
    return &s->buffer_attr;
}


void pa_threaded_mainloop_signal(int *m, int wait_for_accept){
    log("pa_threaded_mainloop_signal: wait_for_accept=%d  Not doing anything here actually\n", wait_for_accept);
    return;
}



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

typedef enum pa_subscription_event_type pa_subscription_event_type_t;

typedef void(* pa_context_subscribe_cb_t)(int *c, pa_subscription_event_type_t t, uint32_t idx, void *userdata);

static pa_context_subscribe_cb_t subscribe_callback;

static void* subscribe_userdata;

void pa_context_set_subscribe_callback  (int *c, pa_context_subscribe_cb_t  cb, void *userdata){
    subscribe_userdata = userdata;
    subscribe_callback = cb;
}

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

typedef void(* pa_context_success_cb_t)(int *c, int success, void *userdata);

int* pa_context_subscribe(int *c, pa_subscription_mask_t m, pa_context_success_cb_t cb, void *userdata){
    log("Subscribing(pa_context_subscribe) mask=%0x   callback=%p   userdata=%p \n", m, cb, userdata);
 
}




typedef struct pa_spawn_api {
    void (*prefork)(void);
    void (*postfork)(void);
    void (*atfork)(void);
} pa_spawn_api;

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


int pa_threaded_mainloop_in_thread(int *m){
    log("Reporting inthread status:%d\n", in_thread);
    return in_thread;
}


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

pa_context_state_t pa_context_get_state(int *c){
    return PA_CONTEXT_READY;
}


enum  	pa_operation_state {
  PA_OPERATION_RUNNING,
  PA_OPERATION_DONE,
  PA_OPERATION_CANCELLED
};

typedef enum pa_operation_state 	pa_operation_state_t;

pa_operation_state_t pa_operation_get_state(int *o){
    log("pa_operation_get_state: reporting operation done\n");
    return PA_OPERATION_DONE;
}

void pa_operation_unref (int *o){
    log("pa_operation_unref: nothing to do\n");
}

void* d_io_new(){
    log("io_new\n");
    return NULL;
}
void d_io_enable(){
    log("io_enable\n");
}
void d_io_free(){
    log("io_free\n");
}
void d_io_set_destroy(){
    log("io_set_destroy\n");
}


void* d_time_new(){
    log("time_new\n");
    return NULL;
}
void d_time_restart(){
    log("time_restart\n");
}
void d_time_free(){
    log("time_free\n");
}
void d_time_set_destroy(){
    log("time_set_destroy\n");
}

void* d_defer_new(){
    log("d_defer_new\n");
    return NULL;
}
void d_defer_enable(){
    log("defer_enable\n");
}
void d_defer_free(){
    log("defer_free\n");
}
void d_defer_set_destroy(){
    log("defer_set_destroy\n");
}

void d_quit(){
    log("quit\n");
}

void* d_rtclock_time_new(){
    log("d_rtclock_time_new\n");
    return NULL;
}
void d_rtclock_time_restart(){
    log("d_rtclock_time_restart\n");
}

void pa_init_i18n(void){
    log("INIT: pa_init_i18n\n");
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
