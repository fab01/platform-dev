<?php

/**
 * @file
 * Altering views for Workbench moderation.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function multisite_workbench_moderation_view_views_default_views_alter(&$views) {

  if (array_key_exists('workbench_moderation', $views)) {
    $view = $views['workbench_moderation'];

    /*
     * ALTER DEFAULT DISPLAY
     */
    $default_view = & $view->display['default'];
    // Add needed new VBO fields.
    $default_view->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
    $default_view->display_options['fields']['views_bulk_operations']['table'] = 'node';
    $default_view->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
    $default_view->display_options['fields']['views_bulk_operations']['relationship'] = 'nid';
    $default_view->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
    $default_view->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
    $default_view->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
    $default_view->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
    $default_view->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
      'action::node_assign_owner_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::views_bulk_operations_delete_item' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::views_bulk_operations_script_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_make_sticky_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_make_unsticky_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::views_bulk_operations_modify_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'settings' => array(
          'show_all_tokens' => 1,
          'display_values' => array(
            '_all_' => '_all_',
          ),
        ),
      ),
      'action::views_bulk_operations_argument_selector_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
        'settings' => array(
          'url' => '',
        ),
      ),
      'action::node_promote_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'rules_component::rules_publish_article' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_publish_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_unpromote_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_save_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::system_send_email_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::workbench_moderation_set_state_action' => array(
        'selected' => 1,
        'postpone_processing' => 0,
        'skip_confirmation' => 1,
        'override_label' => 0,
        'label' => '',
      ),
      'rules_component::rules_unpublish_article' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_unpublish_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::node_unpublish_by_keyword_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
      'action::pathauto_node_update_action' => array(
        'selected' => 0,
        'postpone_processing' => 0,
        'skip_confirmation' => 0,
        'override_label' => 0,
        'label' => '',
      ),
    );

    /*
     * ADD NEW DISPLAY
     */
    /* New Display Page */
    $handler = $view->new_display('page', 'Moderate All', 'moderate_all_page');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Moderate All';
    $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'use workbench_moderation needs review tab';
    $handler->display->display_options['defaults']['empty'] = FALSE;
    // No results behavior: Global: Text area.
    $handler->display->display_options['empty']['area']['id'] = 'area';
    $handler->display->display_options['empty']['area']['table'] = 'views';
    $handler->display->display_options['empty']['area']['field'] = 'area';
    $handler->display->display_options['empty']['area']['empty'] = TRUE;
    $handler->display->display_options['empty']['area']['content'] = 'This list displays content in the selected state that you can moderate. Currently there is no such content.';
    $handler->display->display_options['empty']['area']['format'] = 'plain_text';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    // Contextual filter: Content: Has taxonomy term ID (with depth).
    $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
    $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
    $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
    $handler->display->display_options['arguments']['term_node_tid_depth']['relationship'] = 'nid';
    $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    // Filter criterion: Workbench Moderation: Current.
    $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
    $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
    $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
    $handler->display->display_options['filters']['is_current']['value'] = '1';
    // Filter criterion: Workbench Moderation: State.
    $handler->display->display_options['filters']['state']['id'] = 'state';
    $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
    $handler->display->display_options['filters']['state']['field'] = 'state';
    $handler->display->display_options['filters']['state']['exposed'] = TRUE;
    $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
    $handler->display->display_options['filters']['state']['expose']['label'] = 'Workflow state';
    $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
    $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
    $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
    );
    // Filter criterion: Content: Title.
    $handler->display->display_options['filters']['title']['id'] = 'title';
    $handler->display->display_options['filters']['title']['table'] = 'node';
    $handler->display->display_options['filters']['title']['field'] = 'title';
    $handler->display->display_options['filters']['title']['relationship'] = 'nid';
    $handler->display->display_options['filters']['title']['operator'] = 'contains';
    $handler->display->display_options['filters']['title']['exposed'] = TRUE;
    $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
    $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
    $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
    $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
    $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
    // Filter criterion: Content: Type.
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['relationship'] = 'nid';
    $handler->display->display_options['filters']['type']['exposed'] = TRUE;
    $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
    $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
    $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
    $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
    $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
    $handler->display->display_options['path'] = 'admin/workbench/moderate-all';
    $handler->display->display_options['menu']['type'] = 'tab';
    $handler->display->display_options['menu']['title'] = 'Moderate All';
    $handler->display->display_options['menu']['weight'] = '99';
    $handler->display->display_options['menu']['context'] = 0;

    /*
     * Remove menu tab
     */
    // Remove 'Needs review page' and 'Drafts page' view displays menu tab.
    unset($view->display['drafts_page']->display_options['menu']['type']);
    unset($view->display['needs_review_page']->display_options['menu']['type']);
  }
}
