<?php
/**
 * @file
 */
?>

<?php print $image; ?>

<h3 class="faeprofile-contact-<?php print $faeprofile_id; ?>">Contact</h3>

<?php if ($email): ?><strong>Email:</strong> <?php print $email; ?><br /><?php endif; ?>
<?php if ($phone): ?><strong>Phone:</strong> <?php print $phone; ?><br /><?php endif; ?>
<?php if ($webpage): ?><strong>Website:</strong> <?php print $webpage; ?><br /><?php endif; ?>
<?php if ($room || $building): ?><strong>Location:</strong> <?php print $room; ?>  <?php print $building; ?><br /><?php endif; ?>
<?php if ($supervisor): ?><strong>Supervision:</strong> <?php print $supervisor; ?><?php endif; ?>
