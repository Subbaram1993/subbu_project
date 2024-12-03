#!/bin/bash

# Jenkins URL and credentials
JENKINS_URL=$JENKINS_URL
JENKINS_USERNAME= $JENKINS_USERNAME
JENKINS_PASSWORD= $JENKINS_PASSWORD

# Jenkins job name
JENKINS_JOB_NAME="Subbu_Project_Build"

# Git repository URL
GIT_REPO_URL="https://github.com/Subbaram1993/subbu_project.git"

# Git tag prefix
GIT_TAG_PREFIX="v"

# Trigger Jenkins build
curl -X POST \
  "$JENKINS_URL/job/$JENKINS_JOB_NAME/build" \
  -u "$JENKINS_USERNAME:$JENKINS_PASSWORD" \
  -H 'Content-Type: application/json' \
  -d '{}'

# Get the latest build number from Jenkins
BUILD_NUMBER=$(curl -X GET \
  "$JENKINS_URL/job/$JENKINS_JOB_NAME/lastBuild/buildNumber" \
  -u "$JENKINS_USERNAME:$JENKINS_PASSWORD" \
  -H 'Content-Type: application/json')

# Calculate the version numbers
MAJOR_VERSION=$(($BUILD_NUMBER / 10000))
MINOR_VERSION=$(($BUILD_NUMBER % 10000 / 100))
PATCH_VERSION=$(($BUILD_NUMBER % 100))

# Pad minor and patch versions with leading zeros if less than 10
if [ $MINOR_VERSION -lt 10 ]; then
  MINOR_VERSION="0$MINOR_VERSION"
fi
if [ $PATCH_VERSION -lt 10 ]; then
  PATCH_VERSION="0$PATCH_VERSION"
fi

# Create a new tag in the Git repository
TAG_NAME="$GIT_TAG_PREFIX$MAJOR_VERSION.$MINOR_VERSION.$PATCH_VERSION"
git tag -a "$TAG_NAME" -m "Release $TAG_NAME"

# Push the new tag to the Git repository
git push --tags "$GIT_REPO_URL"
