<?php
/**
 * Overview, Affiliation, Publications, Research, Awards, Linkages, Supervision.
 */

/**
 * Overview page callback for Find an Expert profile information.
 */
function faeprofile_page_overview($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $overview = uom_fae_api_person_overview($uri);

  return theme('faeprofile_overview', array('data' => $overview));
}

/**
 * Affiliation page callback for Find an Expert profile information.
 */
function faeprofile_page_affiliation($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $affiliation = uom_fae_api_person_affiliation($uri);

  return theme('faeprofile_affiliation', array('data' => $affiliation, 'uri' => $uri));
}

/**
 * Publications page callback for Find an Expert profile information.
 */
function faeprofile_page_publications($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $publications = uom_fae_api_person_publications($uri);

  return theme('faeprofile_publications', array('data' => $publications, 'uri' => $uri));
}

/**
 * Research page callback for Find an Expert profile information.
 */
function faeprofile_page_research($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $research = uom_fae_api_person_research($uri);

  return theme('faeprofile_research', array('data' => $research, 'uri' => $uri));
}

/**
 * Awards page callback for Find an Expert profile information.
 */
function faeprofile_page_awards($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $awards = uom_fae_api_person_awards($uri);

  return theme('faeprofile_awards', array('data' => $awards, 'uri' => $uri));
}

/**
 * Linkages page callback for Find an Expert profile information.
 */
function faeprofile_page_linkages($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $linkages = uom_fae_api_person_linkages($uri);

  return theme('faeprofile_linkages', array('data' => $linkages, 'uri' => $uri));
}

/**
 * Supervision page callback for Find an Expert profile information.
 */
function faeprofile_page_supervision($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $supervision = uom_fae_api_person_supervision($uri);

  return theme('faeprofile_supervision', array('data' => $supervision, 'uri' => $uri));
}

/**
 * Contact page callback for Find an Expert profile information.
 */
function faeprofile_page_contact($account) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return drupal_not_found();
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $contact = uom_fae_api_person_contact($uri);

  return theme('faeprofile_contact', array('data' => $contact, 'uri' => $uri));
}

