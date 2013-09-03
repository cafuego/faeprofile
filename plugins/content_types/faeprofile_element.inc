<?php
/**
 * @file
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'content_types' => 'simplecontext_content_type',
  'single' => TRUE,
  'title' => t('Find an Expert element'),
  'render callback' => 'faeprofile_faeprofile_element_content_type_render',

  'icon' => 'icon_unimelb.png',
  'description' => t('Contents of a single Find an Expert element.'),
  'required context' => new ctools_context_required(t('User'), 'user'),

  'edit form' => 'faeprofile_faeprofile_element_edit_form',
  'admin info' => 'faeprofile_faeprofile_element_admin_info',
  'admin title' => 'faeprofile_faeprofile_element_admin_title',
  'category' => t('User'),
  'defaults' => array('element' => '', 'empty' => ''),

);

/**
 * Admin info callback.
 */
function faeprofile_faeprofile_element_admin_info($subtype, $conf, $context = NULL) {
  global $user;
  $context = new stdClass();
  $context->data = clone($user);
  $block = faeprofile_faeprofile_element_content_type_render($subtype, $conf, array('Expert'), $context);
  return $block;
}

/**
 * Admin title callback.
 */
function faeprofile_faeprofile_element_admin_title($subtype, $conf, $context = NULL) {
  return faeprofile_element_label($conf['element']);
}

/**
 * 'Render' callback for the 'faeprofile element' content type.
 */
function faeprofile_faeprofile_element_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = isset($context->data) ? clone($context->data) : NULL;
  $block = new stdClass();
  $block->module = 'faeprofile elements';

  $label = faeprofile_element_label($conf['element']);

  if (!empty($account->field_fae_resource['und'][0]['url'])) {
    $function = 'faeprofile_page_' . $conf['element'];

    $block->subject = $label;
    $block->content = call_user_func($function, $account);
    $block->delta = $account->uid;
  }
  else {
    $block->subject = $label;
    $block->content = $conf['empty'];
    $block->delta   = 'unknown';
  }

  return $block;
}

/**
 * Settings form for the element.
 */
function faeprofile_faeprofile_element_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['element'] = array(
    '#title' => t('Element'),
    '#type' => 'select',
    '#options' => faeprofile_elements(),
    '#default_value' => !empty($conf['element']) ? $conf['element'] : '',
    '#required' => TRUE,
  );
  $form['empty'] = array(
    '#title' => t('Empty text'),
    '#type' => 'textarea',
    '#default_value' => !empty($conf['empty']) ? $conf['empty'] : '',
  );
  return $form;
}

/**
 * Submit handler for the settings form.
 */
function faeprofile_faeprofile_element_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
