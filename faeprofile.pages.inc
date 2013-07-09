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

  $overview = uom_fae_api_person_overview($account->field_fae_resource['und'][0]['url']);
  dpm($overview);

  return theme('faeprofile_overview', array('overview' => $overview));
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
