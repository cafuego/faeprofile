<?php
/**
 * @file
 */
?>

<?php print $image; ?>

<h3>Contact</h3>

<?php if ($email): ?><strong>Email:</strong> <?php print $email; ?><br /><?php endif; ?>
<?php if ($phone): ?><strong>Phone:</strong> <?php print $phone; ?><br /><?php endif; ?>
<?php if ($website): ?><strong>Website:</strong> <?php print $website; ?><br /><?php endif; ?>
<?php if ($room || $building): ?><strong>Location:</strong> <?php print $room; ?>  <?php print $building; ?><br /><?php endif; ?>
<?php if ($supervisor): ?><strong>Supervision:</strong> <?php print $supervisor; ?><?php endif; ?>
