<?php
/**
 * Profile, Overview, Affiliation, Publications, Research, Awards, Linkages, Supervision.
 */

/**
 * Combined selected information page.
 */
function faeprofile_page_faeprofile($account) {
  $enabled = array_filter(variable_get('faeprofile_faeprofile', array()));
  $elements = faeprofile_elements();

  // Pop all enabled main tab elements in a render array.
  $page = array();
  foreach ($enabled as $element) {
    if (!empty($elements[$element]) && user_access('view faeprofile ' . $element)) {
      $callback = 'faeprofile_page_' . $element;
      if (function_exists($callback)) {
        $page[$element] = array('#markup' => $callback($account, FALSE));
      }
    }
  }

  // Render and return.
  return drupal_render($page);
}

/**
 * Profile tab for extra non-FaE information.
 */
function faeprofile_page_information($account, $page = TRUE) {
  $profile = field_get_items('user', $account, 'field_profile_profile');
  if (!variable_get('faeprofile_information', 0) && empty($profile)) {
    return $page ? drupal_not_found() : '';
  }

  return theme('faeprofile_information', array('data' => $profile));
}

/**
 * Overview page callback for Find an Expert profile information.
 */
function faeprofile_page_overview($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $overview = uom_fae_api_person_overview($uri);

  return theme('faeprofile_overview', array('data' => $overview));
}

/**
 * Affiliation page callback for Find an Expert profile information.
 */
function faeprofile_page_affiliations($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $affiliations = uom_fae_api_person_affiliation($uri);

  return theme('faeprofile_affiliations', array('data' => $affiliations, 'uri' => $uri));
}

/**
 * Publications page callback for Find an Expert profile information.
 */
function faeprofile_page_publications($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $publications = uom_fae_api_person_publications($uri);

  return theme('faeprofile_publications', array('data' => $publications, 'uri' => $uri));
}

/**
 * Research page callback for Find an Expert profile information.
 */
function faeprofile_page_research($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $research = uom_fae_api_person_research($uri);

  return theme('faeprofile_research', array('data' => $research, 'uri' => $uri));
}

/**
 * Awards page callback for Find an Expert profile information.
 */
function faeprofile_page_awards($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $awards = uom_fae_api_person_awards($uri);

  return theme('faeprofile_awards', array('data' => $awards, 'uri' => $uri));
}

/**
 * Linkages page callback for Find an Expert profile information.
 */
/*
function faeprofile_page_linkages($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $linkages = uom_fae_api_person_linkages($uri);

  return theme('faeprofile_linkages', array('data' => $linkages, 'uri' => $uri));
}
*/

/**
 * Linkages page callback for Find an Expert profile information.
 */
function faeprofile_page_linkages($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $tmp_linkages = uom_fae_api_person_linkages_no_org_label($uri);
	foreach($tmp_linkages as $key => $tmp_linkage) {
		$org_uri = $tmp_linkage['org'];
		$res = uom_fae_api_person_linkages_org_label($org_uri);

		if(count($res) > 1) {
			// So it is not a single institution, so ignore it
		} else {
			$tmp_linkages[$key]['orgLabel'] = $res[0]['orgLabel']; 
		}
	}	

	$linkages = array_filter($tmp_linkages, "faeprofile_page_linkages_no_org_label_callback");

	return theme('faeprofile_linkages', array('data' => $linkages, 'uri' => $uri));
}

// Call back func used by array_filter
function faeprofile_page_linkages_no_org_label_callback($var) {
	if(!isset($var['orgLabel'])) {
		return false;
	} else {
		return true;
	}
}


/**
 * Supervision page callback for Find an Expert profile information.
 */
function faeprofile_page_supervision($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $supervision = uom_fae_api_person_supervision($uri);

  return theme('faeprofile_supervision', array('data' => $supervision, 'uri' => $uri));
}

/**
 * Contact page callback for Find an Expert profile information.
 */
function faeprofile_page_contact($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $contact = uom_fae_api_person_contact($uri);

  return theme('faeprofile_contact', array('data' => $contact, 'uri' => $uri));
}

/**
 * Qualifications page callback for Find an Expert profile information.
 */
function faeprofile_page_qualifications($account, $page = TRUE) {
  if (empty($account->field_fae_resource['und'][0]['url'])) {
    return $page ? drupal_not_found() : '';
  }

  $uri = $account->field_fae_resource['und'][0]['url'];
  $qualifications = uom_fae_api_person_qualifications($uri);

  return theme('faeprofile_qualifications', array('data' => $qualifications, 'uri' => $uri));
}
