<?php
/**
 * @file
 * Default views.
 */

/**
 * Implements hook_views_default_views().
 */
function islandora_web_annotations_views_default_views() {

    $view = new view();
    $view->name = 'islandora_web_annotation_block_audio_video';
    $view->description = '';
    $view->tag = 'islandora_web_annotations';
    $view->base_table = 'islandora_solr';
    $view->human_name = 'Islandora Web Annotation Block - Audio, Video';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /*
     * Creates the display with common display options and returns the handler.
     */
    function getDisplayHandler($view, $title) {
        $handler = $view->new_display('default', 'Master', 'default');
        $handler->display->display_options['title'] = $title;
        $handler->display->display_options['use_more_always'] = FALSE;
        $handler->display->display_options['access']['type'] = 'none';
        $handler->display->display_options['cache']['type'] = 'none';
        $handler->display->display_options['query']['type'] = 'views_query';
        $handler->display->display_options['exposed_form']['type'] = 'basic';
        $handler->display->display_options['pager']['type'] = 'full';
        $handler->display->display_options['pager']['options']['items_per_page'] = '100';
        $handler->display->display_options['pager']['options']['offset'] = '0';
        $handler->display->display_options['pager']['options']['id'] = '0';
        $handler->display->display_options['pager']['options']['quantity'] = '9';

        /* Contextual filter: Islandora Solr: annotation_parent */
        $handler->display->display_options['arguments']['annotation_parent']['id'] = 'annotation_parent';
        $handler->display->display_options['arguments']['annotation_parent']['table'] = 'islandora_solr';
        $handler->display->display_options['arguments']['annotation_parent']['field'] = 'annotation_parent';
        $handler->display->display_options['arguments']['annotation_parent']['default_action'] = 'default';
        $handler->display->display_options['arguments']['annotation_parent']['default_argument_type'] = 'raw';
        $handler->display->display_options['arguments']['annotation_parent']['default_argument_options']['index'] = '2';
        $handler->display->display_options['arguments']['annotation_parent']['summary']['number_of_records'] = '0';
        $handler->display->display_options['arguments']['annotation_parent']['summary']['format'] = 'default_summary';
        $handler->display->display_options['arguments']['annotation_parent']['summary_options']['items_per_page'] = '25';

        return $handler;
    }

    /* Display: Master */
    $handler = getDisplayHandler($view, "Islandora Web Annotation Block - Audio, Video");
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
        'annotation_value' => 'annotation_value',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
        'annotation_value' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
    /* Field: Islandora Solr: annotation_rangeTimeStart */
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['id'] = 'annotation_rangeTimeStart';
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['field'] = 'annotation_rangeTimeStart';
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['label'] = 'Start';
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['alter']['max_length'] = '6';
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['alter']['trim'] = TRUE;
    $handler->display->display_options['fields']['annotation_rangeTimeStart']['link_to_object'] = 0;
    /* Field: Islandora Solr: annotation_rangeTimeEnd */
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['id'] = 'annotation_rangeTimeEnd';
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['field'] = 'annotation_rangeTimeEnd';
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['label'] = 'End';
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['alter']['max_length'] = '6';
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['alter']['ellipsis'] = FALSE;
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['alter']['trim'] = TRUE;
    $handler->display->display_options['fields']['annotation_rangeTimeEnd']['link_to_object'] = 0;
    /* Field: Islandora Solr: annotation_value */
    $handler->display->display_options['fields']['annotation_value']['id'] = 'annotation_value';
    $handler->display->display_options['fields']['annotation_value']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['annotation_value']['field'] = 'annotation_value';
    $handler->display->display_options['fields']['annotation_value']['label'] = 'Annotation';
    $handler->display->display_options['fields']['annotation_value']['exclude'] = TRUE;
    $handler->display->display_options['fields']['annotation_value']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['annotation_value']['link_to_object'] = 0;
    /* Field: Islandora Solr: Render html field */
    $handler->display->display_options['fields']['annotation_value_render']['id'] = 'annotation_value_render';
    $handler->display->display_options['fields']['annotation_value_render']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['annotation_value_render']['field'] = 'annotation_value_render';
    $handler->display->display_options['fields']['annotation_value_render']['label'] = 'Annotation';
    /* Field: Islandora Solr: fgs_ownerId_s */
    $handler->display->display_options['fields']['fgs_ownerId_s']['id'] = 'fgs_ownerId_s';
    $handler->display->display_options['fields']['fgs_ownerId_s']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['fgs_ownerId_s']['field'] = 'fgs_ownerId_s';
    $handler->display->display_options['fields']['fgs_ownerId_s']['label'] = 'Author';
    $handler->display->display_options['fields']['fgs_ownerId_s']['link_to_object'] = 0;
    /* Sort criterion: Islandora Solr: annotation_rangeTimeStart_sort */
    $handler->display->display_options['sorts']['annotation_rangeTimeStart_sort']['id'] = 'annotation_rangeTimeStart_sort';
    $handler->display->display_options['sorts']['annotation_rangeTimeStart_sort']['table'] = 'islandora_solr';
    $handler->display->display_options['sorts']['annotation_rangeTimeStart_sort']['field'] = 'annotation_rangeTimeStart_sort';

    /* Display: Block */
    $handler = $view->new_display('block', 'Block', 'islandora_annotations_audio_video');

    $views['islandora_web_annotation_block_audio_video'] = $view;

    $view = new view();
    $view->name = 'islandora_web_annotation_block_image_page';
    $view->description = '';
    $view->tag = 'islandora_web_annotations';
    $view->base_table = 'islandora_solr';
    $view->human_name = 'Islandora Web Annotation Block - Image, Page';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = getDisplayHandler($view, "Islandora Web Annotation Block - Image, Page");
    $handler->display->display_options['style_plugin'] = 'list';
    $handler->display->display_options['style_options']['type'] = 'ol';
    $handler->display->display_options['row_plugin'] = 'fields';
    /* Field: Islandora Solr: annotation_value */
    $handler->display->display_options['fields']['annotation_value']['id'] = 'annotation_value';
    $handler->display->display_options['fields']['annotation_value']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['annotation_value']['field'] = 'annotation_value';
    $handler->display->display_options['fields']['annotation_value']['label'] = '';
    $handler->display->display_options['fields']['annotation_value']['exclude'] = TRUE;
    $handler->display->display_options['fields']['annotation_value']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['annotation_value']['link_to_object'] = 0;
    /* Field: Islandora Solr: Render html field */
    $handler->display->display_options['fields']['annotation_value_render']['id'] = 'annotation_value_render';
    $handler->display->display_options['fields']['annotation_value_render']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['annotation_value_render']['field'] = 'annotation_value_render';
    $handler->display->display_options['fields']['annotation_value_render']['label'] = '';
    $handler->display->display_options['fields']['annotation_value_render']['element_label_colon'] = FALSE;
    /* Field: Islandora Solr: fgs_ownerId_ms */
    $handler->display->display_options['fields']['fgs_ownerId_ms']['id'] = 'fgs_ownerId_ms';
    $handler->display->display_options['fields']['fgs_ownerId_ms']['table'] = 'islandora_solr';
    $handler->display->display_options['fields']['fgs_ownerId_ms']['field'] = 'fgs_ownerId_ms';
    $handler->display->display_options['fields']['fgs_ownerId_ms']['label'] = 'Author';
    $handler->display->display_options['fields']['fgs_ownerId_ms']['link_to_object'] = 0;
    /* Sort criterion: Islandora Solr: fgs_createdDate_dt */
    $handler->display->display_options['sorts']['fgs_createdDate_dt']['id'] = 'fgs_createdDate_dt';
    $handler->display->display_options['sorts']['fgs_createdDate_dt']['table'] = 'islandora_solr';
    $handler->display->display_options['sorts']['fgs_createdDate_dt']['field'] = 'fgs_createdDate_dt';

    /* Display: Block */
    $handler = $view->new_display('block', 'Block', 'islandora_annotations_image_page');


    $views['islandora_web_annotation_block_image_page'] = $view;

  return $views;
}

